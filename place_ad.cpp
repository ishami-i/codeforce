#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Videos: [i][0] = start, [i][1] = end
    vector<vector<int>> videos(n, vector<int>(2));
    // TV channels: [j][0] = start, [j][1] = end, [j][2] = views_rate
    vector<vector<int>> tv_channels(m, vector<int>(3));

    // Read videos data
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> videos[i][j];
        }
    }

    // Read TV channels data
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> tv_channels[i][j];
        }
    }

    int max_view = 0;
    int best_video_idx = 0;
    int best_channel_idx = 0;

    // Compare intervals to find maximum views
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int min_range = max(videos[i][0], tv_channels[j][0]);
            int max_range = min(videos[i][1], tv_channels[j][1]);

            if (min_range <= max_range) {
                int overlap_duration = max_range - min_range;
                int views = overlap_duration * tv_channels[j][2];

                if (views > max_view) {
                    max_view = views;
                    best_video_idx = i + 1;    // 1-based index
                    best_channel_idx = j + 1;  // 1-based index
                }
            }
        }
    }
    
    if(max_view == 0) {
        cout << max_view << '\n';
    } else {
        cout << max_view << '\n';
        cout << best_video_idx << " " << best_channel_idx << '\n';
    }

    return 0;
}
