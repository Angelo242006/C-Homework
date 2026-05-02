#include <iostream>
#include <stack>
#include <string>
#include <cmath>

// Comment: When I attended office hours, Professor Naher allowed me to use recursion to evaluate the binary tree and not a stack.

using namespace std;

class Node
{
public:
    string value;
    Node *left;
    Node *right;

    Node(string value1)
    {
        value = value1;
        left = nullptr;
        right = nullptr;
    }
    
};

int precedence (char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    if (op == '^')
    {
        return 3;
    }
    return 0;
}

void inorder (Node *t)
{
    if (t != nullptr)
    {
        inorder(t -> left);

        cout << t->value << " ";
        inorder(t->right);
    }
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int evaluate (Node* root)
{
    if (root->left == nullptr && root -> right == nullptr)
    {
        return stoi(root->value);
    }

    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    switch (root->value[0])
    {
        case '+':
            return leftVal + rightVal;
        case '-':
            return leftVal - rightVal;
        case '*':
            return leftVal * rightVal;
        case '/':
            if (rightVal == 0)
            {
                throw runtime_error("Division by zero.");
            }
            return leftVal / rightVal;
        case '^':
            return (int)pow(leftVal, rightVal);
        default:
            throw runtime_error("Unsupported operator.");
    }
}

string infixToPostfix(string s)
{
    stack<char> st;
    string result;

    int i = 0;
    while (i < (int)s.size())
    {
        char c = s[i];

        if (isdigit(c))
        {
            while (i < (int)s.size() && isdigit(s[i]))
                result += s[i++];
            result += ' ';
            continue;
        }
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                result += ' ';
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                result += st.top();
                result += ' ';
                st.pop();
            }
            st.push(c);
        }
        i++;
    }

    while (!st.empty())
    {
        result += st.top();
        result += ' ';
        st.pop();
    }

    return result;
}

Node* constructTree(string postfix)
{
    stack<Node*> st;
    Node* t, * t1, * t2;

    int i = 0;
    while (i < (int)postfix.size())
    {
        if (postfix[i] == ' ') { i++; continue; }

        if (isdigit(postfix[i]))
        {
            string num;
            while (i < (int)postfix.size() && isdigit(postfix[i]))
                num += postfix[i++];
            st.push(new Node(num));
            continue;
        }
        else
        {
            t = new Node(string(1, postfix[i]));

            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();

            t->right = t1;
            t->left = t2;

            st.push(t);
        }

        i++;
    }

    t = st.top();
    st.pop();

    return t;
}

int main ()
{
    string infix, result;

    cout << "Input your ordinary infix arithmetic expression with integers and operators: " << endl;
    cin >> infix;

    result = infixToPostfix(infix);

    cout << "\nPostfix Expression: " << "\n" << result << "\n" << endl;

    Node *r = constructTree(result);
    cout << "Binary Tree:" << endl;
    inorder(r);
    cout << "\n" << endl;

    try
    {
        cout << "The value of the tree: " << evaluate(r) << endl;
    }
    catch (exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}