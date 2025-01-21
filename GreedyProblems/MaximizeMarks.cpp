#include <bits/stdc++.h>
using namespace std;

struct Question
{
    int id;
    int marks, time;
};

bool compare(Question q1, Question q2)
{
    return q1.marks / q1.time > q2.marks / q2.time;
}

double solveAlone(vector<Question> questions, int T)
{
    sort(questions.begin(), questions.end(), compare);

    double totalTime = T;
    double totalMarks = 0;

    for(int i=0; i<questions.size(); i++)
    {
        if (totalTime >= questions[i].time)
        {
            totalMarks += questions[i].marks;
            totalTime -= questions[i].time;
            cout << "question " << questions[i].id << " : 100% done -->" << questions[i].marks << " marks" << endl;
        }
        else if (totalTime > 0)
        {
            double fraction = totalTime / (double)questions[i].time;
            totalMarks += fraction * questions[i].marks;
            totalTime = 0;
            cout << "question " << questions[i].id << " : " << (int)(fraction * 100) << "% done --> " << fraction * questions[i].marks << " marks" << endl;
        }
        if (totalTime <= 0) break;
    }
    return totalMarks;
}

int main()
{
    int M, T, N;
    cout<<"Enter the total Marks, total Time and total number of Questions respectively: "<<endl;
    cin >> M >> T >> N;

    vector<Question> questions;
    for (int i = 0; i < N; i++)
    {
        int m, t;
        cout<<"Enter question " << i+1 <<"'s mark: ";
        cin >> m;
        cout<<"Enter question " << i+1 <<"'s time: ";
        cin >> t;
        questions.push_back({i + 1, m, t});
    }

    double marksAlone = solveAlone(questions, T);
    cout << "Maximum " << marksAlone << " marks answering alone" << endl;
    double marksWithFriend = solveAlone(questions, T*2);
    cout << "Maximum " << marksWithFriend << " marks answering with a friend" << endl;

    return 0;
}
