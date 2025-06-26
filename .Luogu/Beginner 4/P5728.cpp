#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int count_flag_equal_rivals(int N, const vector<vector<int>>& scores) {
    int count = 0;

    // Check each pair of students
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            // Calculate the differences in scores
            int diff1 = abs(scores[i][0] - scores[j][0]);
            int diff2 = abs(scores[i][1] - scores[j][1]);
            int diff3 = abs(scores[i][2] - scores[j][2]);

            // Calculate total scores
            int total_score1 = scores[i][0] + scores[i][1] + scores[i][2];
            int total_score2 = scores[j][0] + scores[j][1] + scores[j][2];
            int total_diff = abs(total_score1 - total_score2);

            // Check the conditions for flag equal rivals
            if (diff1 <= 5 && diff2 <= 5 && diff3 <= 5 && total_diff <= 10) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int N;
    cin >> N; // Read the number of students

    vector<vector<int>> scores(N, vector<int>(3));
    
    // Read the scores for each student
    for (int i = 0; i < N; ++i) {
        cin >> scores[i][0] >> scores[i][1] >> scores[i][2];
    }

    // Get the count of flag equal rivals
    int result = count_flag_equal_rivals(N, scores);

    // Output the result
    cout << result << endl;

    return 0;
}