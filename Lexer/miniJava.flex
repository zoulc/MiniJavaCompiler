delim		[ \t\n\r]
ws		{delim}+
letter		[A-Za-z]
digit		[0-9]
identifier	(_|{letter})(_|{digit}|{letter})*
number		[+|-]?{digit}+
comment		\/\/[^\n]*

%%
{comment}		{ printf("comment: %s\n", yytext); }
{ws}			{}
class|public|static|void|main|String|extends|return|this	{ printf("class: %s\n", yytext); }
int|boolean		{ printf("type: %s\n", yytext); }
if|else|while		{ printf("control: %s\n", yytext); }
true|false		{ printf("value: %s\n", yytext); }
new|length|System.out.println		{ printf("utility: %s\n", yytext); }
{identifier}				{ printf("identifier: %s\n", yytext); }
{number}				{ printf("number: %s\n", yytext); }
"("|")"|"["|"]"|"{"|"}"			{ printf("bracket: %s\n", yytext); }
"&&"|"<"|"+"|"-"|"*"|"!"|"="		{ printf("operator: %s\n", yytext); }
"."|","|";"		{ printf("punctuation: %s\n", yytext); }
.			{ printf("unrecognized: %s\n", yytext); }
%%

int yywrap() {
	return 1;
}

void main() {
	yylex();
}
