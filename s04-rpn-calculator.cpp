#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
#include <tgmath.h>


auto pop_top(std::stack<double>& stack) -> double
{
    if (stack.empty()) {
        throw std::logic_error{"empty stack"};
    }
    auto element = std::move(stack.top());
    stack.pop();
    return element;
}


auto evaluate_addition(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for +"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a + b);
}

auto evaluate_subtraction(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a - b);
}

auto evaluate_multi(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for *"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a * b);
}

auto evaluate_div(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for /"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    if (b == 0){
        std::cout << "Nie dziel przez 0\n";
        stack.push(0);
    } else {
        stack.push(a / b);
    }
}

auto evaluate_rest(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for %"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    std::cout << "Numbers are rounded down \n";
    stack.push(int(a) % int(b));
}

auto evaluate_intdiv(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for //"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    if (b == 0){
        std::cout << "Nie dziel przez 0\n";
        stack.push(0);
    } else {
        stack.push(int(a) / int(b));
    }
}

auto evaluate_doublemulti(std::stack<double>& stack) -> void
{
    if (stack.size() < 1) {
        throw std::logic_error{"not enough operands for **"};
    }
    auto const a = pop_top(stack);
    stack.push(a * a);
}

auto evaluate_sqrt(std::stack<double>& stack) -> void
{
    if (stack.size() < 1) {
        throw std::logic_error{"not enough operands for sqrt"};
    }
    auto const a = pop_top(stack);
    stack.push(sqrt(a));
}

auto evaluate_power(std::stack<double>& stack) -> void
{
    if (stack.size() < 1) {
        throw std::logic_error{"not enough operands for !"};
    }
    auto const a = pop_top(stack);
    double power = 1; 
    for (auto i = 1; i <= a; i++){
        power = power * i;
    }
    stack.push(power);
}


auto make_args(int argc, char* argv[]) -> std::vector<std::string>
{
    auto args = std::vector<std::string>{};
    std::copy_n(argv, argc, std::back_inserter(args));
    return args;
}

auto main(int argc, char* argv[]) -> int
{
    auto const args = make_args(argc - 1, argv + 1);

    auto stack = std::stack<double>{};
    for (auto const each : args) {
        try {
            if (each == "p") {
                std::cout << pop_top(stack) << "\n";
            } else if (each == "+") {
                evaluate_addition(stack);
            } else if (each == "-") {
                evaluate_subtraction(stack);
            } else if (each == "*") {
                evaluate_multi(stack);
            } else if (each == "/") {
                evaluate_div(stack);
            } else if (each == "%") {
                evaluate_rest(stack);
            } else if (each == "//") {
                evaluate_intdiv(stack);
            } else if (each == "**") {
                evaluate_doublemulti(stack);
            } else if (each == "sqrt") {
                evaluate_sqrt(stack);
            } else if (each == "!") {
                evaluate_power(stack);
            } else {
                stack.push(std::stod(each));
            }
        } catch (std::logic_error const& e) {
            std::cerr << "error: " << each << ": " << e.what() << "\n";
        }
    }

    return 0;
}

