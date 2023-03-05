/* HEADER
   FILE   */

#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>

using namespace std;

/* parent class */
class Gate
{
    public:
        virtual int evaluate() {return 0;}
        void set_gate_name(string name) {gate_name = name;}
        string get_gate_name() {return gate_name;}
        int get_flag() {return flag;}
        void set_flag(int variable) {flag = variable;}

    private:
        string gate_name;
        /* this flag for controls evaluation functions has been run or not */
        int flag = 0;
};

/* children classes */ 
class Gate_Input:public Gate
{
    public:
        int evaluate();
        void set_output_value(int value) {output = value;}

    private:
        /* we store data of input.txt objects which belongs to this class */
        int output;
};

class Gate_And:public Gate
{
    public:
        int evaluate();
		void set_input_name1(string name) {input_name1 = name;}
		void set_input_name2(string name) {input_name2 = name;}
        void set_input_gate1(Gate *gate1) {input_gate1 = gate1;}
        void set_input_gate2(Gate *gate2) {input_gate2 = gate2;}
        string get_input_name1() {return input_name1;}
		string get_input_name2() {return input_name2;}

    private:
        /* and gate has two inputs and we store name of these inputs */
        string input_name1, input_name2;
        /* and we keeping these adres of this input gates */
        Gate *input_gate1, *input_gate2;
        /* we store input values */
        int input1, input2;
        /* and gate has one output value */
        int output;      
};

class Gate_Or:public Gate
{
    public:
        int evaluate();
		void set_input_name1(string name) {input_name1 = name;}
		void set_input_name2(string name) {input_name2 = name;}
        void set_input_gate1(Gate* gate1) {input_gate1 = gate1;}
        void set_input_gate2(Gate* gate2) {input_gate2 = gate2;}
        string get_input_name1() {return input_name1;}
		string get_input_name2() {return input_name2;}

    private:
        /* or gate has two inputs and we store name of these inputs */
        string input_name1, input_name2;
        /* we keeping these adres of this input gates */
        Gate *input_gate1, *input_gate2;
        /* we store input values */
        int input1, input2;
        /* or gate has one output value */
        int output;  
};

class Gate_Not:public Gate
{
    public:
        int evaluate();
		void set_input_name(string name) {input_name = name;}
        void set_input_gate(Gate* gate) {input_gate = gate;}
        string get_input_name() {return input_name;}

    private:
        /* not gate has one input and we store name of these inputs */
        string input_name;
        /* we keeping these adres of this input gate */
        Gate* input_gate;
        /* we store input value */
        int input;
        /* not gate has one output value */
        int output;
};

class Gate_Flip_Flop:public Gate
{
    public:
        int evaluate();
        void set_input_name(string name) {input_name = name;}
        void set_input_gate(Gate* gate) {input_gate = gate;}
        string get_input_name() {return input_name;}

    private:
        /* flipflop gate has one input and we store name of these inputs */
        string input_name;
        /* we keeping these adres of this input gate */
        Gate* input_gate;
        /* we store input value */
        int input;
        /* also flipflop gate has memory and we using it when we calculating output */
        int memory = 0;
        /* flipflop gate has one output value */
        int output; 
};

class Gate_Decoder:public Gate
{
    public:
        int evaluate();
        void set_gate_name1(string name) {gate_name1 = name;}
        void set_gate_name2(string name) {gate_name2 = name;}
        void set_gate_name3(string name) {gate_name3 = name;}
        void set_gate_name4(string name) {gate_name4 = name;}

        string get_gate_name1() {return gate_name1;}
        string get_gate_name2() {return gate_name2;}
        string get_gate_name3() {return gate_name3;}
        string get_gate_name4() {return gate_name4;}

		void set_input_name1(string name) {input_name1 = name;}
		void set_input_name2(string name) {input_name2 = name;}
        void set_input_gate1(Gate* gate1) {input_gate1 = gate1;}
        void set_input_gate2(Gate* gate2) {input_gate2 = gate2;}

        string get_input_name1() {return input_name1;}
		string get_input_name2() {return input_name2;}    

    private:
        /* decoder has four outputs and we store these output names */
        string gate_name1, gate_name2, gate_name3, gate_name4;
        /* decoder gate has two inputs and we store name of these inputs */
        string input_name1, input_name2;
        /* we keeping these adres of this input gates */
        Gate *input_gate1, *input_gate2;
        /* we store input values */
        int input1, input2;
        /* decoder gate has four output values */
        int output1, output2, output3, output4;
};

class Gate_Output:public Gate
{
    public:
        int evaluate();
        void set_input_gate(Gate* gate) {input_gate = gate;}
        Gate* get_input_gate() {return input_gate;}

    private:
        /* this pointer points to last gate before the output */
        Gate* input_gate;
        /* and this is the result of particular output */
        int output;
};

typedef struct myStrct
{
    /* variables for keep count of some informations */
    int number_of_inputs = -1, number_of_outputs = -1, number_of_and_gates = 0, number_of_or_gates = 0, 
        number_of_not_gates = 0, number_of_flipflop_gates = 0, number_of_decoder_gates = 0; 
    
    /* pointers for keep head of every dynamic array */
    Gate_Input* head_point_inputs;
    Gate_Output* head_point_outputs;
    Gate_And* head_point_and_gates;
    Gate_Or* head_point_or_gates;
    Gate_Not* head_point_not_gates;
    Gate_Flip_Flop* head_point_flipflop_gates;
    Gate_Decoder* head_point_decoder_gates;
}myStruct;

int Gate_Input::evaluate()
{
    /* input gates only returns which what stores in it */
    return this->output;
}

int Gate_And::evaluate()
{
    /* if particular object function haven't been run than execute below code */
    if(get_flag() == 0)
    {
        /* first we get input values */
        this->input1 = input_gate1->evaluate();
        this->input2 = input_gate2->evaluate();
        /* after that make some logical calculation according to and gate and assign it to output variable */
        this->output = input1 && input2;
        /* change flag value for don't execute this function again */
        set_flag(1);
    }

    /* finally returns output variable */
    return this->output;
}

int Gate_Or::evaluate()
{
    /* if particular object function haven't been run than execute below code */
    if(get_flag() == 0)
    {
        /* first we get input values */
        this->input1 = input_gate1->evaluate();
        this->input2 = input_gate2->evaluate();
        /* after that make some logical calculation according to or gate and assign it to output variable */
        this->output = input1 || input2;
        /* change flag value for don't execute this function again */
        set_flag(1);
    }

    /* finally returns output variable */
    return this->output;
}

int Gate_Not::evaluate()
{
    /* if particular object function haven't been run than execute below code */
    if(get_flag() == 0)
    {
        /* first we get input values */
        this->input = input_gate->evaluate();
        /* after that make some logical calculation according to not gate and assign it to output variable */
        if(input == 1) output = 0;
        else output = 1;
        /* change flag value for don't execute this function again */
        set_flag(1);
    }

    /* finally returns output variable */
    return this->output;
}

int Gate_Flip_Flop::evaluate()
{
    /* if particular object function haven't been run than execute below code */
    if(get_flag() == 0)
    {    
        /* first we get input values */
        this->input = input_gate->evaluate();
        /* after that make some logical calculation according to flipflop gate and assign it to output variable
           according to input value we are we deciding if output value is going to be equal memory or not */
        if(input == 0) output = memory;
        else
        {
            /* according to memory value we changing output value */
            if(memory == 0)
            {
                output = 1;
                memory = output; /* free memory */
            }

            else
            {
                output = 0;
                memory = output; /* free memory */
            }
        }
        /* change flag value for don't execute this function again */
        set_flag(1);
    }

    /* finally returns output variable */
    return this->output;
}

int Gate_Decoder::evaluate()
{
    /* if particular object function haven't been run than execute below code */    
    if(get_flag() == 0)
    {
        /* first we get input values */
        this->input1 = input_gate1->evaluate();
        this->input2 = input_gate2->evaluate();
        /* after that make some logical calculation according to decoder gate and assign it to output variable */
        if(input1 == 0 && input2 == 0)
        {
            output1 = 1;
            output2 = 0;
            output3 = 0;
            output4 = 0;
        }

        if(input1 == 0 && input2 == 1)
        {
            output1 = 0;
            output2 = 1;
            output3 = 0; 
            output4 = 0;
        }

        if(input1 == 1 && input2 == 0)
        {
            output1 = 0; 
            output2 = 0;
            output3 = 1;
            output4 = 0;
        }

        if(input1 == 1 && input2 == 1)
        {
            output1 = 0;
            output2 = 0;
            output3 = 0;
            output4 = 1;
        }

        /* we just printing output values. this gate can be only end of the circuit */
        cout << output1 << " " << output2 << " " << output3 << " " << output4 << " "; 
        /* change flag value for don't execute this function again */
        set_flag(1);
    }
    
    return 0;
}

int Gate_Output::evaluate()
{
    /* everythink begens with this evaluate functions */
    this->output = input_gate->evaluate();
    /* and return value gives us our final output */
    return output;
}

#endif