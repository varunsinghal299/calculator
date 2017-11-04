
//mini  project of 4th sem by VARUN SINGHAL AND MANSI BANSAL................................



#include<stdio.h>                  //header files
#include<string.h>

// declaration of structure which contain one character , two pointer(next & prev) of same type i.e of struct node type .
struct node
{
    char info;
    struct node *next;
    struct node *prev;

};
typedef struct node nd;     //BY THIS WE HAVE TO TYPECASTE THE NAME OF "struct node" to "nd".

// PRIORITY FFUNCTION having return type integer.
// which will return the value of int according to the precedence ( + and - have higher precedence than * and / ) ..
int priority(char x)
{
    if(x=='(')
        return 1;
    if(x == '+' || x == '-')
        return 3;
    if(x == '*' || x == '/')
        return 2;

}

// char array name defined is stack here .
// for storing the value of operator i.e +,-,*,/ according to the precedence ....
// here we also declared the top value of stack (char array ) i.e of int type & initially stack is empty therefore value of top taken be -1...

char stack[20];
int top =-1;

// push function is defined here which will increment the value of top & push the operator in stack(char array) according to the precedence ...
void push(char x)
{
        stack[++top] = x;
}
// pop function is defined here which will pop the character at value top & then decrement the value of top ....
char pop()
{
        if(top == -1)
                return -1;
        else
            return stack[top--];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DECLARATION OF THE CHAR ARRAY for store the postfix form of given infix expression after change in proper form.......

char postfix[100];
int j=0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DECLARATION OF THE CHAR ARRAY FOR store the given infix expression ..........and after some small change in that expression we
// also store the new proper infix expression
// HERE WE INITIALIZE THE int type of "le" datatype which will store the LENGTH OF INFIX EXP....
char s[100];
int le;


// CONVERT FUNCTION WHICH WILL USE TO CONVERT THE PROPER INSERT INFIX EXP INTO POSTFIX EXP and store the new postfix exp into postfix (char array)..

void convert(){

   int i,t;
   char c;
   for(i=0 ; i<le ; i++){

       if(s[i]=='('){
           push(s[i]);
           i=i+1;
       }
       else if(s[i]==' '){
             if('0'<=s[i-1] && s[i-1]<='9'){
                postfix[j++]=' ';
             }
       }
       else if('0'<=s[i] && s[i]<='9'){
                postfix[j++]=s[i];
                continue;

      }
       else if(s[i]=='+' || s[i]=='-'  || s[i]=='*' || s[i]=='/'){

                          while(priority(stack[top])>=priority(s[i])){

                                c=pop();
                                postfix[j++]=c;
                                postfix[j++]=' ';
                         }

                       push(s[i]);

       }
       else if(s[i]==')'){

             while((c = pop()) != '('){

                  postfix[j++]=c;
                  postfix[j++]=' ';

             }

       }
   }
   postfix[j++]=' ';
    while(top != -1)
    {
          c=pop();
          postfix[j++]=c;
          postfix[j++]=' ';

    }

}
//HERE WE INITIALIZE THE int array name i.e eva which is used to evaluate the our result after converting the given infix exp into postfix exp
//the initialize the value of 'k' of integer type & initially the value of k is 1 bcoz we have to enter the value of number from index 1 if eva array....
int eva[100]={0};
int k=0;

//popp function which is used to return the the top most value of eva array at value k & then decrement the value of k........
int popp(){
   if(k==-1){
       return 0;
   }
   else {
        eva[k]=0;
        return eva[--k];
   }

}

//this function gives the value of result of converted postfix exp.
int evaluate(){

    int i;

    for(i= 0 ;  i<j ; i++){

        if(postfix[i]<='9' && '0'<=postfix[i]){
            eva[k]=eva[k]*10+(postfix[i]-'0');
        }
        else if(postfix[i]==' '){
            if(postfix[i-1]<='9' && '0'<=postfix[i-1]){
                k++;

            }
        }
        else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/'){

            int op1,op2;
            op2=popp();
            op1=popp();
            switch(postfix[i])
            {
               case '+':eva[k++]=(op1+op2); break;
               case '-':eva[k++]=(op1-op2);break;
               case '*':eva[k++]=(op1*op2);break;
               case '/': if(op2==0)
                           //HERE IF WE GOT THE NUMBER WHICH IS DIVISIBLE BY '0' SO OUR ANS IS  ---UNDEFINED--
                           {    printf("\n   UNDIFINED ANS  \n");
                                return -1212120;
                           }
                        eva[k++]=(op1/op2);
                        break;
           }

        }

    }

 return eva[k-1];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CHECK FUNCTION TO CHECK WHEATHER THE STRING ENTER IS WRITE OR WRONG
int arr[100];
int oops=0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
int main(int argc,char *argv[]){


    int i,d;
    char c;
     int flag=1;
        int rr;


    printf("\n\nenter the space-deliminated infix expression ->");
    scanf("%[^\n]s",s);
    le=strlen(s);

    if(le==0){
        printf("\n INPUT IS NOT GIVEN\n");
        return 0;
    }

    flag=1;

    for(rr=0 ; rr<le ; rr++){

       if(flag==1){

            if(s[rr]=='-'){
                flag=2;
                continue;
            }
            else if(s[rr]<='9' && s[rr]>='0'){
                flag=4;
                continue;
            }
            else {
                 printf("\n   INPUT IS WRONG  \n");
                 return 0;
            }
       }
       else if(flag==2){

            if(s[rr]==' '){
                flag=3;
                continue;
            }
            else{
                 printf("\n   INPUT IS WRONG  \n");
                return 0;
            }

       }
       else if(flag==3){

           if(s[rr]<='9' && s[rr]>='0'){
            flag=4;
            continue;
           }
           else{
                printf("\n   INPUT IS WRONG  \n");
                return 0;

           }



       }
       else if(flag==4){
          if(s[rr]<='9' && s[rr]>='0' ){
            continue;
          }
          else if(s[rr]==' '){
            flag=5;
            continue;
          }
          else{
             printf("\n   INPUT IS WRONG  \n");
            return 0;
          }
       }
       else if(flag==5){
           if(s[rr]=='+' || s[rr]=='-' || s[rr]=='*' || s[rr]=='/'){
            flag=6;
            continue;
           }
           else{
            printf("\n   INPUT IS WRONG  \n");
            return 0;
           }
       }
       else if(flag==6){
           if(s[rr]==' '){
             flag=7;
             continue;
           }
           else{
              printf("\n   INPUT IS WRONG  \n");
             return 0;
           }
       }
       else if(flag==7){
            if(s[rr]<='9' && s[rr]>='0'){
                flag=4;
                continue;
            }
            else if(s[rr]=='-'){
                flag=2;
                continue;
            }
            else{
                printf("\n   INPUT IS WRONG  \n");
                return 0;
            }
       }


    }

   if(flag==4){

    nd *l=NULL,*r=NULL,*temp1,*temp2,*p,*q,*temp,*temp3,*temp4;

// here WE STORE THE INFIX EXPRESSION IN FORM OF DOUBLE LINKED LIST TO MAKE IT PROPER by simple method...........

    for(i=0  ; i<le ; i++){
          p=(nd*)malloc(sizeof(nd));
          p->info=s[i];
          p->next=NULL;
          p->prev=NULL;

        if(l==NULL)
        {
            l=p;
            r=p;
        }
        else{

            r->next=p;
            p->prev=r;
            r=p;
        }
    }

// here we convert the infix exp. into proper infix exp. by inserting brackets and '0' before unary negation operator (also -).

    temp=l;

    if(temp->info=='-'&&temp->next->info==' '){

        p=(nd*)malloc(sizeof(nd));
        p->info='(';
        p->prev=NULL;
        p->next=NULL;

        temp1=p;
        temp2=p;

        p=(nd*)malloc(sizeof(nd));
        p->info=' ';
        p->prev=temp2;
        p->next=NULL;
        temp2->next=p;
        temp2=p;

        p=(nd*)malloc(sizeof(nd));
        p->info='0';
        p->prev=temp2;
        p->next=NULL;
        temp2->next=p;
        temp2=p;

        p=(nd*)malloc(sizeof(nd));
        p->info=' ';
        p->prev=temp2;
        p->next=NULL;
        temp2->next=p;
        temp2=p;



        temp2->next=l;
        l->prev=temp2;

        temp=(l->next)->next;
        l=temp1;

        while('0'<=temp->info<='9' && temp!=NULL && temp->info!=' ' ){
            temp=temp->next;
        }
        temp3=temp->prev;
        temp4=temp;


            p=(nd*)malloc(sizeof(nd));
            p->info=' ';
            p->next=NULL;
            p->prev=NULL;

            q=(nd*)malloc(sizeof(nd));
            q->info=')';
            q->next=NULL;
            q->prev=NULL;

            temp3->next=p;
            p->prev=temp3;

            p->next=q;
            q->prev=p;

            q->next=temp4;
            temp4->prev=q;



    }

    temp=l;

    while((temp->next)->next!=NULL){

       //  printf("ggGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGg");
        if((temp->info=='+' || temp->info=='-' || temp->info=='*' || temp->info=='/' )&&(temp->next->info==' ') && (((temp->next)->next)->info=='-') ){

            temp1=temp->next;
            temp2=temp1->next;



            p=(nd*)malloc(sizeof(nd));
            p->info='(';
            p->next=NULL;
            p->prev=temp1;
            temp3=temp4=p;

            p=(nd*)malloc(sizeof(nd));
            p->info=' ';
            p->next=NULL;
            p->prev=temp4;
            temp4->next=p;
            temp4=p;

            p=(nd*)malloc(sizeof(nd));
            p->info='0';
            p->next=NULL;
            p->prev=temp4;
            temp4->next=p;
            temp4=p;

            p=(nd*)malloc(sizeof(nd));
            p->info=' ';
            p->next=NULL;
            p->prev=temp4;
            temp4->next=p;
            temp4=p;


            temp1->next=temp3;
            temp3->prev=temp1;

            temp4->next=temp2;
            temp2->prev=temp4;


            temp2=temp2;
            temp1=temp2->next;

            temp=(temp2->next);

            //printf("\n%c\n",temp->info);
             while('0'<=(temp->next)->info<='9' && (temp->next)!=NULL && (temp->next)->info!=' ' ){
                   temp=temp->next;
             }

            if(temp->next==NULL){

                 p=(nd*)malloc(sizeof(nd));
                 p->info=' ';
                 p->next=NULL;
                 p->prev=NULL;

                 q=(nd*)malloc(sizeof(nd));
                 q->info=')';
                 q->next=NULL;
                 q->prev=NULL;


                 temp->next=p;
                 p->prev=temp;

                 p->next=q;
                 q->prev=p;



            }
            else{

            temp3=temp;
            temp4=temp->next;


            p=(nd*)malloc(sizeof(nd));
            p->info=' ';
            p->next=NULL;
            p->prev=NULL;

            q=(nd*)malloc(sizeof(nd));
            q->info=')';
            q->next=NULL;
            q->prev=NULL;

            temp3->next=p;
            p->prev=temp3;

            p->next=q;
            q->prev=p;

            q->next=temp4;
            temp4->prev=q;

        }




    }

     temp=temp->next;


    }


// here we print the proper infix exp.  ....................................................................
    temp=l;
    printf("\nProper infix form of given expression is -> ");
    while(temp!=NULL){
        printf("%c",temp->info);
        temp=temp->next;
    }
    printf("\n");

//THIS IS USE TO STORE THE PROPER INFIX EXPRESSSION AND STORE IN INTO CHAR ARRAY i.e s[100].....

    temp=l;
    i=0;

    while(temp!=NULL){
        s[i]=temp->info;
        i++;
        temp=temp->next;
    }
    le=i;

// HERE WE CALL CONVERT FUNCTION WHICH WILL CONVERT OUR INFIX EXP. INTO POSTFIX EXP. & STORE THAT POSTFIX EXP.
// INTO CHAR ARRAY HAVING NAME IS POSTFIX .........................................................................

    convert();

// here we print the our postfix exp..............................................................................
    printf("\npostfix expression is ->");
    printf("%s\n",postfix);

// here we call evaluate function whiv=ch will

    int val=evaluate();
    if(val==-1212120){
        return 0;
    }

    printf("\nresult is ->%d\n\n",val);

   }

   else {

// if value of flag is != 4 then our infix exp entered is not correct entered then we print "INPUT IS WRONG ".....
      printf("\n   INPUT IS WRONG  \n");
      return 0;

   }



    return 0;
}
