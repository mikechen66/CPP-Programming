
/* Change the in-order traversal to the Post-order traversal */

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
#define MAX 50

/* Use it to save the queue with the in-order representation */
char infix_q[MAX];                                                      
int compare(char stack_o, char infix_o) {
    /* The priority is INDEX/2 */                              
    char infix_priority[9] ; 
    char stack_priority[8] ;
    int index_s=0, index_i=0;

    infix_priority[0]='q';infix_priority[1]=')';
    infix_priority[2]='+';infix_priority[3]='-';
    infix_priority[4]='*';infix_priority[5]='/';
    infix_priority[6]='^';infix_priority[7]=' ';
    infix_priority[8]='(';      
    stack_priority[0]='q';stack_priority[1]='(';
    stack_priority[2]='+';stack_priority[3]='-';
    stack_priority[4]='*';stack_priority[5]='/';
    stack_priority[6]='^';stack_priority[7]=' ';

    while (stack_priority[index_s] != stack_o)
        index_s++;
    while (infix_priority[index_i] != infix_o)
        index_i++;
    return ((int)(index_s/2) >= (int)(index_i/2) ? 1 : 0);
}

/* Change the in-order method to the pre-order method */ 
void infix_to_postfix() {
    int rear=0, top=0, flag=0,i=0;
    char stack_t[MAX];  
    for (i=0; i<MAX; i++) {
        stack_t[i]='\0';
        gets(infix_q);
        i=0;
        while (infix_q[i]!='\0') {
            i++;
            rear++;
        }
        infix_q[rear] = 'q';  /* q is an ending symbol */
        cout<<"\t"<<"Postorder representation: ";
        stack_t[top]  = 'q';  
        
        for (flag = 0; flag <= rear; flag++) {       
            switch (infix_q[flag]) {
                // Output the operands while inputting ")" */
                case ')':
                    while (stack_t[top]!='(')                  
                        cout<<setw(1)<<stack_t[top--];                 
                    top--;
                    break;
                /* Ouput the operands while the inbput is q */
                case 'q':
                    while (stack_t[top]!='q')
                        cout<<setw(1)<<stack_t[top--];
                    break;
                /* The input is operator */
                case '(':
                case '^':
                case '*':
                case '/':
                case '+':
                case '-': 
                    while (compare(stack_t[top], infix_q[flag])==1)                       
                        cout<<setw(1)<<stack_t[top--];          
                    stack_t[++top] = infix_q[flag];
                    break;
                //Output the result while the input is an operand */
                default :                          
                    cout<<setw(1)<<infix_q[flag];
                    break;
            }
        }
    }
}

int main (void) { 
    int i=0;
    for (i=0; i<MAX; i++)
        infix_q[i]='\0';    
        cout<<"\t=========================================="<<endl;
        cout<<"\tThe program transform it to the postorder representation"<<endl;
    cout<<"\tPlease input the middle order representation"<<endl;
    cout<<"\tFor example:(9+3)*8+7*6-8/4 "<<endl;
    cout<<"\tUsers can use the following operators: ^,*,+,-,/,(,), etc "<<endl;
    cout<<"\t=========================================="<<endl;
    cout<<"\tPlease input the middle order representation: ";
    infix_to_postfix();
    cout<<endl;
    cout<<"\t=========================================="<<endl;    
    return 0; 
}



/* Output */

/*
main.cpp:43:9: warning: ¡®char* gets(char*)¡¯ is deprecated [-Wdeprecated-declarations]
         gets(infix_q);
         ^~~~
In file included from /usr/include/c++/6/cstdio:42:0,
                 from /usr/include/c++/6/ext/string_conversions.h:43,
                 from /usr/include/c++/6/bits/basic_string.h:5429,
                 from /usr/include/c++/6/string:52,
                 from /usr/include/c++/6/bits/locale_classes.h:40,
                 from /usr/include/c++/6/bits/ios_base.h:41,
                 from /usr/include/c++/6/ios:42,
                 from /usr/include/c++/6/ostream:38,
                 from /usr/include/c++/6/iostream:39,
                 from main.cpp:5:
/usr/include/stdio.h:638:14: note: declared here
 extern char *gets (char *__s) __wur __attribute_deprecated__;
              ^~~~
main.cpp:43:21: warning: ¡®char* gets(char*)¡¯ is deprecated [-Wdeprecated-declarations]
         gets(infix_q);
                     ^
In file included from /usr/include/c++/6/cstdio:42:0,
                 from /usr/include/c++/6/ext/string_conversions.h:43,
                 from /usr/include/c++/6/bits/basic_string.h:5429,
                 from /usr/include/c++/6/string:52,
                 from /usr/include/c++/6/bits/locale_classes.h:40,
                 from /usr/include/c++/6/bits/ios_base.h:41,
                 from /usr/include/c++/6/ios:42,
                 from /usr/include/c++/6/ostream:38,
                 from /usr/include/c++/6/iostream:39,
                 from main.cpp:5:
/usr/include/stdio.h:638:14: note: declared here
 extern char *gets (char *__s) __wur __attribute_deprecated__;
              ^~~~
/tmp/cctq6Y7V.o: In function `infix_to_postfix()':
main.cpp:(.text+0x132): warning: the `gets' function is dangerous and should not be used.
        ==========================================
        The program transform it to the postorder representation
        Please input the middle order representation
        For example:(9+3)*8+7*6-8/4 
        Users can use the following operators: ^,*,+,-,/,(,), etc 
        ==========================================
        Please input the middle order representation: 
 */