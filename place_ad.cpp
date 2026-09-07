#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Event {
    int time;
    int type; // 0: Video Start, 1: TV Start, 2: TV End, 3: Video End
    int id;   
    int rate; 

    bool operator<(const Event& other) const {
        if (time != other.time) return time < other.time;
        return type > other.type; // Process End events before Start events on ties
    }
};

struct Channel {
    int rate;
    int end_time;
    int id;

    // Sort primarily by rate ascending, then by end_time ascending
    bool operator<(const Channel& other) const {
        if (rate != other.rate) return rate < other.rate;
        if (end_time != other.end_time) return end_time < other.end_time;
        return id < other.id;
    }
};

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Event> events;
    vector<pair<int, int>> videos(n + 1);
    vector<pair<int, int>> tv_channels(m + 1);
    vector<int> tv_rates(m + 1);

    for (int i = 1; i <= n; i++) {
        cin >> videos[i].first >> videos[i].second;
        events.push_back({videos[i].first, 0, i, 0});
        events.push_back({videos[i].second, 3, i, 0});
    }

    for (int i = 1; i <= m; i++) {
        int start, end, rate;
        cin >> start >> end >> rate;
        tv_channels[i] = {start, end};
        tv_rates[i] = rate;
        events.push_back({start, 1, i, rate});
        events.push_back({end, 2, i, rate});
    }
    
    sort(events.begin(), events.end());

    long long max_view = 0;
    int best_video_idx = 0;
    int best_channel_idx = 0;

    set<pair<int, int>> active_videos; // {end_time, id}
    set<Channel> active_channels;      // Sorted Pareto-front of active channels

    for (const auto& event : events) {
        if (event.type == 0) { 
            // Video Start
            active_videos.insert({videos[event.id].second, event.id});
            
            // Sweep across the highly pruned, non-dominated active channels
            for (const auto& ch : active_channels) {
                int overlap = min(videos[event.id].second, ch.end_time) - event.time;
                if (overlap > 0) {
                    long long views = (long long)overlap * ch.rate;
                    if (views > max_view) {
                        max_view = views;
                        best_video_idx = event.id;
                        best_channel_idx = ch.id;
                    }
                }
            }
        } 
        else if (event.type == 1) { 
            // TV Channel Start
            if (!active_videos.empty()) {
                auto max_vid = *active_videos.rbegin(); 
                int vid_id = max_vid.second;
                int overlap = min(videos[vid_id].second, tv_channels[event.id].second) - event.time;
                if (overlap > 0) {
                    long long views = (long long)overlap * event.rate;
                    if (views > max_view) {
                        max_view = views;
                        best_video_idx = vid_id;
                        best_channel_idx = event.id;
                    }
                }
            }

            // Insert into active channels with Pareto optimization
            Channel new_ch = {event.rate, tv_channels[event.id].second, event.id};
            
            // Check if new_ch is dominated by an existing channel with higher/equal rate
            auto it = active_channels.lower_bound({event.rate, 0, 0});
            bool dominated = false;
            while (it != active_channels.end()) {
                if (it->end_time >= new_ch.end_time) {
                    dominated = true;
                    break;
                }
                it++;
            }

            if (!dominated) {
                // Remove any channels with lower/equal rate that this new channel now dominates
                it = active_channels.lower_bound({event.rate, 0, 0});
                while (it != active_channels.begin()) {
                    it--;
                    if (it->end_time <= new_ch.end_time) {
                        it = active_channels.erase(it);
                    } else {
                        break; // Since end_time increases as rate decreases in a pruned set
                    }
                }
                active_channels.insert(new_ch);
            }
        } 
        else if (event.type == 2) { 
            // TV Channel End
            active_channels.erase({tv_rates[event.id], tv_channels[event.id].second, event.id});
        } 
        else if (event.type == 3) { 
            // Video End
            active_videos.erase({videos[event.id].second, event.id});
        }
    }
    
    cout << max_view << '\n';
    if (max_view > 0) {
        cout << best_video_idx << " " << best_channel_idx << '\n';
    }
 
    return 0;
}
