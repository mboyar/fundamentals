#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/*
 * Author: Murat Boyar (as the CANDIDATE)
 */

/*
 * CANDIDATE'S NOTE: I am using QtCreator IDE at this time to develop task's code, so I will copy/paste all code soon..
 */

string solution(string &S, string &C) {
    // write your code in C++14 (g++ 6.2.0)

    /*
     * CANDIDATE'S NOTE:
     * split by comma by using thread-safe strtok_r
     * and so I also should use some core C language abilities in this case
     */

    map<string, string> map_name;
    vector <string> vector_nameEmail;

    char *save_ptr;
    char *m_S = (char *)malloc(S.length());
    char *m_token;
    const char* m_delim = ",";
    const char* m_wspace = " ";
    string str_result;

    strcpy(m_S, S.c_str());
    m_token = strtok_r(m_S, m_delim, &save_ptr);

    std::transform(C.begin(), C.end(), C.begin(), ::tolower);

    while(m_token != NULL){
//        cout << "dbg start: ----------------------->" << endl;

        string str_token(m_token);
        string str_token_lower = str_token;
        std::transform(str_token_lower.begin(), str_token_lower.end(), str_token_lower.begin(), ::tolower);

        str_token.erase(0, str_token.find_first_not_of(m_wspace));

        str_token_lower.erase(0, str_token_lower.find_first_not_of(m_wspace));
        str_token_lower.erase(std::remove(str_token_lower.begin(), str_token_lower.end(), '-'), str_token_lower.end());

//        cout << str_token_lower << endl;

        char *save_ptr2;
        char *m_token2;
        const char *m_delim2 = " ";
        char *cstr_token = (char *)malloc(str_token_lower.length());

        strcpy(cstr_token, str_token_lower.c_str());
        m_token2 = strtok_r(cstr_token, m_delim2, &save_ptr2);

        string str_subname1, str_subname2, str_subname3;
        int index = 0;

        while (m_token2 != NULL) {
//            cout << "dbg2 start: ----------------------->" << endl;

            string str_token2(m_token2);

            if(index == 0){

                str_subname1 = str_token2;
            }
            else if (index == 1) {

                str_subname2 = str_token2;
            }
            else if (index == 2) {

                str_subname3 = str_token2;
            }

//            cout << "dbg2 end: <-----------------------" << endl;

            ++index;
            m_token2 = strtok_r(NULL, m_delim2, &save_ptr2);
        }

//        cout << "str_name1:" << str_subname1 << endl;
//        cout << "str_name2:" << str_subname2 << endl;
//        cout << "str_name3:" << str_subname3 << endl;

        string str_nameEmail;

        if(index == 3) str_nameEmail = str_subname3 + "." + str_subname1.at(0) + "." + str_subname2.at(0);
        if(index == 2) str_nameEmail = str_subname2 + "." + str_subname1.at(0);

        map_name[str_token] = str_nameEmail;

//        cout << "dbg end: <-----------------------" << endl;
        m_token = strtok_r(NULL, m_delim, &save_ptr);
    }

    /*
     * Updating the repeated email address occurrences
     */
    int indexRepeatedEmailAddr = 1;
    for (auto iterMap=map_name.begin(); iterMap!=map_name.end(); ++iterMap){
        //std::map<string, string>::iterator iter2 = iter++;

//        cout << iterMap->first << " => " << iterMap->second << endl;
//        cout << iter2->first << " => " << iter2->second << endl;

        string str_nameNormal = iterMap->first;
        string str_nameEmail = iterMap->second;

        auto iterVect = find(vector_nameEmail.begin(), vector_nameEmail.end(), str_nameEmail);

        if(iterVect != vector_nameEmail.end()){
//            cout << "vector_nameEmail repeated element: " << *iterVect << indexRepeatedEmailAddr << endl;
            str_nameEmail = *iterVect + std::to_string(indexRepeatedEmailAddr);
            map_name[str_nameNormal] = str_nameEmail;
            indexRepeatedEmailAddr++;
        }
        else{
            indexRepeatedEmailAddr = 1;
        }

//        cout << iterMap->first << " => " << iterMap->second << endl;

        vector_nameEmail.push_back(str_nameEmail);

        str_result += str_nameNormal + " <" + str_nameEmail + "@" + C + ".com>";

        if(std::next(iterMap) == map_name.end())
            str_result += ".";
        else
            str_result += ", ";
    }


    free(m_S);
    return str_result;
}

int main()
{
    string sList = "John Doe, Peter Parker, Mary Jane Watson-Parker, James Doe, John Elvis Doe, Jane Doe, Penny Parker, Jack Doe";
    string cList = "Amazon";

    cout << solution(sList, cList) << endl;

    return 0;
}

