#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream in("input.cpp");
    ofstream out("output.cpp");
    char ch, nextChar;

    while (in.get(ch))
    {
        if (ch == '/')
        {
            bool flag = false;
            in.get(nextChar);

            if (nextChar == '/')
            {
                flag = true;
                while (in.get(ch) && ch != '\n')
                {
                    if (ch == '\\' && in.get(ch) && ch == '\n')
                    {
                        break;
                    }
                }
            }
            else if (nextChar == '*')
            {
                flag = true;
                while (in.get(ch))
                {
                    if (ch == '*' && in.get(nextChar) && nextChar == '/')
                    {
                        break;
                    }
                }
            }

            if (!flag)
            {
                out.put('/');
                ch = nextChar;
            }
            else
            {
                continue;
            }
        }

        if (ch == '"')
        {
            out.put(ch);
            while (in.get(ch) && ch != '"')
            {
                out.put(ch);
            }
        }

        out.put(ch);
    }

    cout<<"Comment remove successfully from input.cpp and result in output.cpp"<<endl;
    return 0;
}
