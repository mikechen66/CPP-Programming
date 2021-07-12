#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "error.h"
#include "lexer.h"

namespace ch10
{
    using std::string;
    using std::vector;
    using std::map;
    using std::istream;
    using std::ostream;

    typedef vector<string> ParamList;
    typedef vector<double> ArgumentList;
    typedef vector<Token> TokenList;
    typedef double (*FunctionPtr)(double);

    struct SymEntry
    {
        enum SymType {
            NONE, VAR, SYS_FUNC, USR_FUNC
        };
        SymType type;

        SymEntry() : type(NONE) {}
        SymEntry(SymType type) : type(type) {}
    };

    struct SymVariable : SymEntry
    {
        double value;

        SymVariable(double value) : SymEntry(VAR), value(value) {}
    };

    struct SymSysFunc : SymEntry
    {
        FunctionPtr func;

        SymSysFunc(FunctionPtr func) : SymEntry(SYS_FUNC), func(func) {}
    };

    struct SymUsrFunc : SymEntry
    {
        TokenList func;
        ParamList params;

        SymUsrFunc(TokenList func, ParamList params) : SymEntry(USR_FUNC), func(func), params(params) {}
    };

    class SymbolTable
    {
        map<string, SymEntry*> items;

    public:
        bool Exists(const string& name) const { return items.count(name) > 0; }
        void Set(const string& name, SymEntry* symbol) { items[name] = symbol; }
        SymEntry* Get(string& name) { return items[name]; }
        ~SymbolTable() { for(map<string,SymEntry*>::const_iterator i = items.begin(); i != items.end(); i++)delete i->second; }
    };

    class Calculator
    {
        SymbolTable symbols;

        ParamList parameters(Lexer&);
        ArgumentList arguments(Lexer&);
        double call(Lexer&, string);
        double expr(Lexer&);
        double func(Lexer&);
        double prim(Lexer&);
        double term(Lexer&);

    public:
        Calculator();
        void register_function(const string& name, FunctionPtr func);
        void register_variable(const string& name, double value);
        double eval(const string& expr);
        int eval(istream* input, ostream* output, ostream* error);
    };
}

#endif
