# Compiler Design Basics
COMPANY: CODTECH IT SOLUTIONS

NAME: SRIJAN KUMAR

INTERN ID: CT06DH541

DOMAIN: C++

DURATION: 6 WEEKS

MENTOR: NEELA SANTOSH

DESCRIPTION:

The Basic Expressions Evaluator is a C++ implementation of a simple expression interpreter, developed as part of a compiler design study. It demonstrates the essential stages of compilation — lexical analysis, parsing, and evaluation — applied to arithmetic expressions. This project takes an input expression, such as `"3 + 5 * (2 - 4)"`, and computes its result while respecting operator precedence, associativity rules, and parenthetical grouping. Although lightweight compared to full-scale compilers, the project effectively encapsulates the core logic of expression processing in a structured and educational manner.

From a technical perspective, the evaluator is composed of three primary stages that mimic those found in real compilers:

1. **Lexical Analysis (Tokenization)** —
   The first stage reads the input expression string and breaks it into a sequence of *tokens*, where each token represents a meaningful unit such as a number, an operator (`+`, `-`, `*`, `/`), or parentheses. The tokenizer ignores whitespace and validates each token’s format, ensuring that the evaluator can process only valid arithmetic inputs. The lexical analyzer is implemented using character-by-character scanning with conditional logic to detect digits, operators, and special symbols.

2. **Parsing (Syntax Analysis)** —
   After tokenization, the sequence of tokens is fed into a parser, which determines the structural meaning of the expression according to predefined grammar rules. In this project, parsing is implemented either through:

   * **Recursive Descent Parsing** — a top-down approach with separate functions for handling expressions, terms, and factors.
   * or **Shunting Yard Algorithm** — converting infix expressions to postfix (Reverse Polish Notation) for easier evaluation.
     The parser enforces operator precedence rules (multiplication/division before addition/subtraction) and handles nested parentheses by recursive calls or stack-based processing.

3. **Evaluation (Semantic Analysis & Execution)** —
   Once the expression is parsed into an intermediate form (such as postfix notation), the evaluator processes it to compute the final numeric result. In the postfix evaluation method, a stack is used: numbers are pushed onto the stack, and when an operator is encountered, the appropriate number of operands is popped, the operation is applied, and the result is pushed back. This continues until the final result is obtained.

Error handling is integrated at multiple stages to ensure robustness. The lexical analyzer reports invalid characters, the parser flags mismatched parentheses or unexpected tokens, and the evaluator prevents runtime errors such as division by zero. These checks provide clear, user-friendly error messages to help identify and correct input mistakes.

The program’s architecture is modular, separating the responsibilities of tokenization, parsing, and evaluation into distinct functions or classes. This separation of concerns makes the codebase more maintainable and allows individual components to be modified or extended without affecting others. For example, the evaluator could be extended to handle floating-point arithmetic, exponentiation, or even variables by simply enhancing the lexer and parser rules.

To maintain precision and correctness, the evaluator stores numeric values as `double` or `long long` types, depending on whether floating-point or integer evaluation is desired. Operator precedence and associativity rules are implemented using either a precedence table or parser function hierarchy. Parentheses handling is a key feature, allowing evaluation of deeply nested expressions without ambiguity.

From a compiler design education perspective, this project serves as an excellent introduction to how programming languages handle expressions. While it omits advanced features like symbol tables, type checking, or code generation, it clearly demonstrates the front-end compilation process — breaking down input into tokens, validating and structuring it according to grammar, and executing it to produce a result.

This Basic Expressions Evaluator is a practical demonstration of how even simple compilers work at their core. It is ideal for showcasing knowledge in **compiler theory, parsing algorithms, stack-based computation, and C++ programming**. The project also reinforces understanding of algorithmic thinking, as implementing correct precedence handling, recursion, and stack operations requires careful logic design. Furthermore, its modularity means it can serve as the foundation for more complex interpreters or compilers in future projects.

Output:
![img](https://github.com/user-attachments/assets/4e245a23-7fb2-4dd0-b9ac-f60a2babdf21)
