// -------------------------------------------------------------
//
// This Flex program produces the corresponding C code to display
// all the declarions of another C code file.
//
// Author: Aggelos Stamatiou, May 2017
//
// This source code is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this source code. If not, see <http://www.gnu.org/licenses/>.
// --------------------------------------------------------------

%{
#define T_SYSLIB 250
#define T_USERLIB 251
#define T_MACRDEF 252
#define T_FORFUNCDECL 253
#define T_FUNCDEF 254

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int libraries = 0;
int fwfuncdecls = 0;
int fundefs = 0;

%}

ws [ \t]+
newline \n|\x0A|\x0D\x0A
digit (0|[0-9]) 
integers {digit}+
floats  {integers}(\.{integers})
letter [A-Za-z]
id {letter}+(_|{letter})*
type {id}
pointer \*
table \[\]
variable {pointer}?{id}({id}|{digit})*|{id}({id}|{digit})*{table}{0,2}
incl #include
def #define
syslib  {incl}{ws}<{id}.h>
userlib {incl}{ws}\"{id}.h\"
macrdef {def}{ws}{variable}{ws}({integers}|{floats})
expression {type}{ws}{variable}(\,{ws}{type}{ws}{variable})*
forfuncdecl {type}{ws}{id}\({expression}\)\;
funcdef {type}{ws}{id}\({expression}\)

%%

{ws}   	{/* Do nothing */}
{syslib} {libraries++;return(T_SYSLIB);}
{userlib} {libraries++;return(T_USERLIB);}
{macrdef} {return(T_MACRDEF);}
{forfuncdecl} {fwfuncdecls++;return(T_FORFUNCDECL);}
{funcdef} {fundefs++;return(T_FUNCDEF);}
{newline} {/*Do nothing*/}
.     {/*Do nothing*/}

%%

/* Code that takes a filename as an argument */ 
int main(int argc, char ** argv )
{   
	int token;
	++argv, --argc;  /* skip over program name */
   	if ( argc > 0 ){yyin = fopen( argv[0], "r" );}
   	else {yyin = stdin;}
	
	while ((token=yylex()) != 0)
	{
		if(token==250){printf("System Library: %s\n",yytext);}
		else if(token==251){printf("User Library: %s\n",yytext);}
		else if(token==252){printf("Macro definition: %s\n",yytext);}
		else if(token==253){printf("Forward Function Declaration: %s\n",yytext);}
		else if(token==254){printf("Function Definition: %s\n",yytext);}	
	}

	printf("%d Libraries are included in file.\n",libraries);
	printf("There are %d fw function declarations and %d fun defs.\n",fwfuncdecls,fundefs);

}
