grammar QBorrow;

program : statement+ ;



statement 
    : 'let' ID '=' expr ';'
    | 'borrow' reg ';'
    | 'alloc' reg ';'
    | 'X' '[' reg ']' ';'
    | 'CNOT' '[' reg ',' reg ']' ';'
    | 'CCNOT' '[' reg ',' reg ',' reg ']' ';'
    | 'for' ID '=' expr 'to' expr '{' statement+ '}'
    ;


reg
    : ID '[' expr ']'
    | ID 
    ;

// arithmetic expressions
expr 
    : expr ADD term 
    | expr SUB term
    | SUB term
    | ADD term
    | term 
    ;


term 
    : term MUL factor 
    | factor
    ;

factor
    : NUMBER
    | ID
    | '(' expr ')'
    ;


ADD : '+';
SUB : '-';
MUL : '*';



ID : [a-zA-Z_] [a-zA-Z0-9_]* ;
NUMBER : [0-9]+ ;
WS : [ \t\r\n]+ -> skip ;

LINE_COMMENT  : '//' ~[\r\n]*     -> skip ;
BLOCK_COMMENT : '/*' .*? '*/'     -> skip ;