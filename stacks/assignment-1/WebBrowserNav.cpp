#include <iostream>
#include <string>
#include <stdbool.h>

#include "StackString.h"

using namespace std;

class WebBrowserNav
{
public:
    StackString backwardStack;
    StackString forwardStack;

    WebBrowserNav(int size)
    {
        forwardStack = StackString(size);
        backwardStack = StackString(size);
    }

    void visitPage(string currentPage)
    {
        backwardStack.push(currentPage);
    }

    void back()
    {
        if (backwardStack.top > 0)
        {
            string poppedPage = backwardStack.pop();
            forwardStack.push(poppedPage);
            cout << "Navigated to --> " << backwardStack.stack[backwardStack.top] << endl;
            return;
        }
        cout << "There is nothing to go back to" << endl;
    }

    void forward()
    {
        string poppedPage = forwardStack.pop();
        if (poppedPage.length() != 0)
        {
            backwardStack.push(poppedPage);
            cout << "Navigated to --> " << backwardStack.stack[backwardStack.top] << endl;
            return;
        }
        cout << "There is nothing to go forwardStack to" << endl;
    }

    string currentPage()
    {
        return backwardStack.stack[backwardStack.top];
    }

    void instructions()
    {
        cout << "1. Go to a page" << endl;
        cout << "2. Go to previous page" << endl;
        cout << "3. Go to next page" << endl;
        cout << "4. Display contents\n"
             << endl;
    }
};

int main()
{
    WebBrowserNav nav = WebBrowserNav(5);
    nav.instructions();

    bool run = true;
    string newPage;

    while (run)
    {
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<"\n"<<endl;

        switch (choice)
        {
        case 1:
            cout << "Enter url: ";
            cin >> newPage;

            nav.backwardStack.push(newPage);
            cout << "\n--- You are on --> " << nav.currentPage() << "\n"
                 << endl;
            break;

        case 2:
            nav.back();
            cout << "\n--- You are on -->" << nav.currentPage() << "\n"
                 << endl;
            break;

        case 3:
            nav.forward();
            cout << "--- You are on -->" << nav.currentPage() << "\n"
                 << endl;
            break;

        case 4:
            nav.backwardStack.viewItems();
            break;

        default:
            run = false;
        }
    }
    return 0;
}