#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Song {
    int genreTotal;
    int playCount;
    int index;
};

bool compare(Song a, Song b) {
    if (a.genreTotal != b.genreTotal) {
        return a.genreTotal > b.genreTotal;
    }

    if (a.playCount != b.playCount) {
        return a.playCount > b.playCount;
    }

    return a.index < b.index;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    int n = genres.size();
    unordered_map<string, int> times;

    for (int i = 0; i < n; ++i) {
        times[genres[i]] += plays[i];
    }

    vector<Song> songs;

    for (int i = 0; i < n; ++i) {
        Song song;
        song.genreTotal = times[genres[i]];
        song.playCount = plays[i];
        song.index = i;

        songs.push_back(song);
    }

    sort(songs.begin(), songs.end(), compare);

    // 정렬된 순서대로 장르마다 최대 두 곡 선택
    unordered_map<string, int> selected;
    vector<int> answer;

    for (int i = 0; i < n; ++i) {
        int index = songs[i].index;
        string genre = genres[index];

        if (selected[genre] < 2) {
            answer.push_back(index);
            ++selected[genre];
        }
    }

    return answer;
}