#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

struct Node
{
    string theme;
    vector<int> answer_list;
};

int index_of_answer(vector<Node>& v, int answer)
{
    int index;

    for (int i = 0; i < v.size(); i++)
    {
        if (!v[i].answer_list.empty())
            for (int j = 0; j < v[i].answer_list.size(); j++)
            {
                if (answer == v[i].answer_list[j])
                    return i;
            }
    }
    return 0;
}


int main()
{
    SetConsoleCP(1251);

    int messages_count;
    vector<Node> new_themes;
    string tmp;

    getline(std::cin, tmp);
    messages_count = stoi(tmp);
    int i = 0;
    int mess_ans;

    while (i++ < messages_count)
    {
        getline(std::cin, tmp);
        mess_ans = stoi(tmp);
        if (mess_ans == 0)
        {
            Node temp;
            temp.answer_list.push_back(i);

            getline(std::cin, temp.theme);
            getline(std::cin, tmp);
            new_themes.push_back(temp);
        }
        else
        {
            new_themes[index_of_answer(new_themes, mess_ans)].answer_list.push_back(i);
            getline(std::cin, tmp);
        }
    }
    int max_res = 0;
    int index = 0;
    for (int i = 0; i < new_themes.size(); i++)
    {
        if (new_themes[i].answer_list.size() > max_res)
        {
            max_res = new_themes[i].answer_list.size();
            index = i;
        }
    }
    cout << new_themes[index].theme << endl;
}
