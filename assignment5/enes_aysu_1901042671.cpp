#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

#include "class.h"

using namespace std;

/* function declaretions */
void read_circuit_file(myStruct& strct);
void reset_gate_flag(myStruct& strct);
void run_circuit(myStruct& strct);
int find_row_input_file();
void read_input_file(myStruct& strct);
Gate* find_input_gate(string input_gate_name, myStrct& strct);
void generate_circuit(myStruct& strct);
void find_number_of_gates(myStruct& strct);

int main()
{
    myStruct strct;

    /* finds number of gates */
    find_number_of_gates(strct);

	/* after provide memory for every gate using dynamic allocation. and store their head points */
	strct.head_point_inputs = new Gate_Input[strct.number_of_inputs];
	strct.head_point_outputs = new Gate_Output[strct.number_of_outputs];
	strct.head_point_and_gates = new Gate_And[strct.number_of_and_gates];
	strct.head_point_or_gates = new Gate_Or[strct.number_of_or_gates];
	strct.head_point_not_gates = new Gate_Not[strct.number_of_not_gates];
    strct.head_point_flipflop_gates = new Gate_Flip_Flop[strct.number_of_flipflop_gates];
    strct.head_point_decoder_gates = new Gate_Decoder[strct.number_of_decoder_gates];

    /* after that read circuit file and store the data to objects */
	read_circuit_file(strct);
    /* after that provide connection between gates */
	generate_circuit(strct);
    /* finally read input data and run the circuit */
    read_input_file(strct);
}

/* this function finds number of input, output and other gates and stores them */
void find_number_of_gates(myStruct& strct)
{
    int count = 0;
    string line, 
           word;

    ifstream file;

    file.open("circuit.txt");

    /* get first line */
    getline(file, line);
 	stringstream sstream1(line);

	/* parse first line according to ' ' character */
    while (getline(sstream1, word, ' '))
    {
        /* for each word increase number_of_inputs */
        strct.number_of_inputs += 1;
    }

	/* we do same thing for second line which belongs to OUTPUT names */
    /* get second line */
    getline(file, line);
 	stringstream sstream2(line);
	
    while (getline(sstream2, word, ' '))
    {
        /* for each word increase number_of_outputs */
        strct.number_of_outputs += 1;
    }

    /* rest of the file according to keywords increase count of particular number of gate */
    while(file >> word)
    {
		if(word == "AND") 
        {
            /* increse number_of_and_gates */
            strct.number_of_and_gates += 1;
		}
			
		if(word == "OR") 
        {
            /* increse number_of_or_gates */
            strct.number_of_or_gates += 1;
		}

		if(word == "NOT")
        {
            /* increse number_of_not_gates */
            strct.number_of_not_gates += 1;
		}

        if(word == "FLIPFLOP")
        {
            /* increse number_of_flipflop_gates */
            strct.number_of_flipflop_gates += 1;
		}

        if(word == "DECODER")
        {
            /* increse number_of_decoder_gates */
            strct.number_of_decoder_gates += 1;
		}
    }

	file.close();
}

/* this function reads circuit.txt and stores information in it to objects */
void read_circuit_file(myStruct& strct)
{
    int i, c_and = 0, c_or = 0, c_not = 0, c_flipflop = 0, c_decoder = 0;
    string word;

    ifstream file;
    file.open("circuit.txt");

    file >> word; /* first keyword is INPUT */

    for(i = 0; i < strct.number_of_inputs; i++){ /* program continues reading count of number_of_inputs */
        file >> word;
        strct.head_point_inputs[i].set_gate_name(word); /* and stores inputs name to object */
    }

    file >> word; /* second keyword is OUTPUT */

    for(i = 0; i < strct.number_of_outputs; i++){ /* program continues reading count of number_of_outputs */
        file >> word;
        strct.head_point_outputs[i].set_gate_name(word); /* and stores outputs name to object */
    }

    /* rest of the code according to keyword in every head of line, makes some storage */
    while(file >> word)
    {
        /* if keyword is AND */
		if(word == "AND"){ 
			/* keeps reading tree times because and gate has two inputs and one output */
            for(i = 0; i < 3; i++)
            {
				file >> word;
				if(i == 0)
                {
					strct.head_point_and_gates[c_and].set_gate_name(word);
				}
				else if(i == 1)
                {
					strct.head_point_and_gates[c_and].set_input_name1(word);
				}
				else
                {
					strct.head_point_and_gates[c_and].set_input_name2(word);
				}
			}

            /*if there is more and gate move to next one */
			c_and++;
		}
			
        /* if keyword is OR */    
		if(word == "OR")
        {
            /* keeps reading tree times because or gate has two inputs and one output */
			for(i = 0; i < 3; i++){
				file >> word;
				if(i == 0)
                {
					strct.head_point_or_gates[c_or].set_gate_name(word);
				}
				else if(i == 1)
                {
					strct.head_point_or_gates[c_or].set_input_name1(word);
				}
				else
                {
					strct.head_point_or_gates[c_or].set_input_name2(word);
				}
			}

            /*if there is more or gate move to next one */
			c_or++;
		}

        /* if keyword is OR */
		if(word == "NOT")
        {
            /* keeps reading two times because not gate has one input and one output */
			for(i = 0; i < 2; i++)
            {
				file >> word;
				if(i == 0)
                {
					strct.head_point_not_gates[c_not].set_gate_name(word);
				}
				else
                {
					strct.head_point_not_gates[c_not].set_input_name(word);
				}
			}
            
            /* if there is more not gate move to next one */
			c_not++;
		}

        /* if keyword is FLIPFLOP */
		if(word == "FLIPFLOP")
        {
            /* keeps reading two times because flipflop gate has one input and one output */
			for(i = 0; i < 2; i++)
            {
				file >> word;
				if(i == 0)
                {
					strct.head_point_flipflop_gates[c_flipflop].set_gate_name(word);
				}
				else
                {
					strct.head_point_flipflop_gates[c_flipflop].set_input_name(word);
				}
			}

            /* if there is more flipflop gate move to next one */
			c_flipflop++;
		}

        /* if keyword is DECODER */
        if(word == "DECODER")
        {
            /* keeps reading six times. because decoder gate has two inputs and four output */
			for(i = 0; i < 6; i++)
            {
				file >> word;
				if(i == 0){
					strct.head_point_decoder_gates[c_decoder].set_gate_name1(word);
				}
                if(i == 1){
					strct.head_point_decoder_gates[c_decoder].set_gate_name2(word);
				}
                if(i == 2){
					strct.head_point_decoder_gates[c_decoder].set_gate_name3(word);
				}
                if(i == 3){
					strct.head_point_decoder_gates[c_decoder].set_gate_name4(word);
				}
				if(i == 4){
					strct.head_point_decoder_gates[c_decoder].set_input_name1(word);
				}
				if(i == 5){
					strct.head_point_decoder_gates[c_decoder].set_input_name2(word);
				}
			}

            /* if there is more flipflop gate move to next one */
			c_decoder++;
		}
    }

	file.close();
}

/* this function connects input gates with current gate */
void generate_circuit(myStruct& strct)
{
    int i;
    Gate* local;

    for(i = 0; i < strct.number_of_and_gates; i++) 
    { /* for every first input of and gates */ 
        local = find_input_gate(strct.head_point_and_gates[i].get_input_name1(), strct); /* after finding particular gate */
        strct.head_point_and_gates[i].set_input_gate1(local); /* just make connection between input gate and current gate */
    }

    for(i = 0; i < strct.number_of_and_gates; i++)
    { /* for every second input of and gates */
        local = find_input_gate(strct.head_point_and_gates[i].get_input_name2(), strct); /* after finding particular gate */
        strct.head_point_and_gates[i].set_input_gate2(local); /* just make connection between input gate and current gate */
    }

    for(i = 0; i < strct.number_of_or_gates; i++)
    { /* for every first input of or gates */
        local = find_input_gate(strct.head_point_or_gates[i].get_input_name1(), strct); /* after finding particular gate */
        strct.head_point_or_gates[i].set_input_gate1(local); /* just make connection between input gate and current gate */
    }

    for(i = 0; i < strct.number_of_or_gates; i++)
    { /* for every second input of or gates */
        local = find_input_gate(strct.head_point_or_gates[i].get_input_name2(), strct); /* after finding particular gate */
        strct.head_point_or_gates[i].set_input_gate2(local); /* just make connection between input gate and current gate */
    }

    for(i = 0; i < strct.number_of_not_gates; i++)
    { /* for every input of not gates */
        local = find_input_gate(strct.head_point_not_gates[i].get_input_name(), strct); /* after finding particular gate */
        strct.head_point_not_gates[i].set_input_gate(local); /* just make connection between input gate and current gate */
    }

    for(i = 0; i < strct.number_of_flipflop_gates; i++)
    { /* for every input of flipflop gates */
        local = find_input_gate(strct.head_point_flipflop_gates[i].get_input_name(), strct); /* after finding particular gate */
        strct.head_point_flipflop_gates[i].set_input_gate(local); /* just make connection between input gate and current gate */
    }  

    for(i = 0; i < strct.number_of_decoder_gates; i++)
    { /* for every first input of flipflop gates */
        local = find_input_gate(strct.head_point_decoder_gates[i].get_input_name1(), strct); /* after finding particular gate */
        strct.head_point_decoder_gates[i].set_input_gate1(local); /* just make connection between input gate and current gate */
    }

    for(i = 0; i < strct.number_of_decoder_gates; i++)
    { /* for every second input of decoder gates */
        local = find_input_gate(strct.head_point_decoder_gates[i].get_input_name2(), strct); /* after finding particular gate */
        strct.head_point_decoder_gates[i].set_input_gate2(local); /* just make connection between input gate and current gate */
    }   

    for(i = 0; i < strct.number_of_outputs; i++)
    { /* for every input of output gates */
        local = find_input_gate(strct.head_point_outputs[i].get_gate_name(), strct); /* after finding particular gate */
        strct.head_point_outputs[i].set_input_gate(local); /* just make connection between input gate and current gate */
    }
}

/* this function stores data of input.txt and stores it in particular objects(input gates) */
void read_input_file(myStruct& strct)
{ 
	int data;
	int i = 0;
	
	ifstream file;
    file.open("input.txt");

    /* for every row we exacute below code again */
    for(int j = 0; j < find_row_input_file(); j++)
    {
        /* we keep reading according to number_of_inputs to reach end of the line */
        for(i = 0; i < strct.number_of_inputs; i++)
        {   
            file >> data;
            /* and store that data in particular object */
            strct.head_point_inputs[i].set_output_value(data);
        }

        /* runs circuit for specific line of input.txt */
        run_circuit(strct);
        /* and reset base flag for next inputs so evaluation function can performs again */
        reset_gate_flag(strct);
    }

	file.close();
}

/* if input.txt file has more than one row, this function resets flag in the base gate so for new inputs evaluation functions can run again */
void reset_gate_flag(myStruct& strct)
{
    int i;

	/*for every gate(object) we are reseting flag in the base gate */
    for(i = 0; i < strct.number_of_and_gates; i++)
    { /* this loop for and gates(objects) */
        strct.head_point_and_gates[i].set_flag(0);
    }

    for(i = 0; i < strct.number_of_or_gates; i++)
    { /* this loop for or gates(objects) */
        strct.head_point_or_gates[i].set_flag(0);
    }

    for(i = 0; i < strct.number_of_not_gates; i++)
    { /* this loop for not gates(objects) */
        strct.head_point_not_gates[i].set_flag(0);
    }

    for(i = 0; i < strct.number_of_flipflop_gates; i++)
    { /* this loop flipflop gates(objects) */
        strct.head_point_flipflop_gates[i].set_flag(0);
    }

    for(i = 0; i < strct.number_of_decoder_gates; i++)
    { /* this loop for decoder gates(objects) */
        strct.head_point_decoder_gates[i].set_flag(0);
    }
}

/* this function runs the circuit and prints the outputs on the terminal */
void run_circuit(myStruct& strct)
{
    int flag = 1;

    /* for every output we call evaluate function of output gates */
    for(int i = 0; i < strct.number_of_outputs; i++)
    {

        for(int j = 0; j < strct.number_of_decoder_gates; j++)
        { //we search every decoder gates, if output belongs to decoder or not */
            if(strct.head_point_outputs[i].get_input_gate() == &strct.head_point_decoder_gates[j])
            { /* if output is belongs to decoder we set local flag as 0 */
                flag = 0;
            }
            else
            { /* if output is not belongs to decoder we set local flag as 1 */
                flag = 1;
            }
        }

        /* if output is belongs the decoder gate we just call evaluate function of output */
        if(flag == 0)
        {
            strct.head_point_outputs[i].evaluate();
        } 

        /* if output is not belongs the decoder gate we call evaluate function of output and prints it */   
        else
        {
            cout  << strct.head_point_outputs[i].evaluate() << " ";
        }    
    }

    cout << endl;
}

/* this function finds row of input.txt */
int find_row_input_file()
{
    int count = 0;
    string line, word;

    ifstream file;
    file.open("input.txt");

    /* if there is line just increase count by one */
    while(getline(file, line))
    {
        count++;
    }

	file.close();
    return count;
}

/* this function compares gate names with input names and returns particular gate adress */
Gate* find_input_gate(string input_gate_name, myStrct& strct)
{
    int i;

    for(i = 0; i < strct.number_of_inputs; i++)
    {
        if(strct.head_point_inputs[i].get_gate_name() == input_gate_name) /* if particular gate name same as input_gate_name */
            return &strct.head_point_inputs[i]; /* just return address of particular gate(object) */
    }

    for(i = 0; i < strct.number_of_and_gates; i++)
    {
        if(strct.head_point_and_gates[i].get_gate_name() == input_gate_name) /* if particular gate name same as input_gate_name */
            return &strct.head_point_and_gates[i]; /* just return address of particular gate(object) */
    }

    for(i = 0; i < strct.number_of_or_gates; i++)
    {
        if(strct.head_point_or_gates[i].get_gate_name() == input_gate_name) /* if particular gate name same as input_gate_name */ 
            return &strct.head_point_or_gates[i]; /* just return address of particular gate(object) */
    }

    for(i = 0; i < strct.number_of_not_gates; i++)
    {
        if(strct.head_point_not_gates[i].get_gate_name() == input_gate_name) /* if particular gate name same as input_gate_name */
            return &strct.head_point_not_gates[i]; /* just return address of particular gate(object) */
    }

    for(i = 0; i < strct.number_of_flipflop_gates; i++)
    {
        if(strct.head_point_flipflop_gates[i].get_gate_name() == input_gate_name) //if particular gate name same as input_gate_name */
            return &strct.head_point_flipflop_gates[i]; /* just return address of particular gate(object) */
    }

    for(i = 0; i < strct.number_of_decoder_gates; i++)
    {
        if(strct.head_point_decoder_gates[i].get_gate_name1() == input_gate_name || 
           strct.head_point_decoder_gates[i].get_gate_name2() == input_gate_name ||
           strct.head_point_decoder_gates[i].get_gate_name3() == input_gate_name ||
           strct.head_point_decoder_gates[i].get_gate_name4() == input_gate_name) /* decoder have four name, if one of particular gate name same as input_gate_name */
        return &strct.head_point_decoder_gates[i]; /* just return address of particular gate(object) */
    }

    /* this is insignificant, avoid for compile errors */
    return &strct.head_point_decoder_gates[i];
}




