//https://leetcode.com/discuss/interview-experience/499002/Google-Interview-or-L3L4-or-Jan-2020-(Reject)
#include "common.hpp"

class TopKElements {
private:
    list<int> cnts;
    unordered_map<string, list<int>::iterator> key2cnt;
    unordered_map<int, unordered_set<string>> cnt2key;

public:
    void increment(const string& key) {
        if (key2cnt.count(key)) {
            auto iter = key2cnt[key];
            auto cnt = *iter;
            if (next(iter) == cnts.end() || *next(iter) != cnt + 1) {
                key2cnt[key] = cnts.insert(next(iter), cnt + 1);
            } else {
                key2cnt[key] = next(iter);
            }
            cnt2key[cnt].erase(key);
            if (cnt2key[cnt].empty()) {
                cnts.erase(iter);
                cnt2key.erase(cnt);
            }
            cnt2key[cnt + 1].insert(key);
        } else {
            if (cnts.empty() || cnts.front() != 1) {
                cnts.push_front(1);
            }
            key2cnt[key] = cnts.begin();
            cnt2key[1].insert(key);
        }
    }

    int get(const string& key) {
        if (key2cnt.count(key)) {
            return *key2cnt[key];
        } else {
            return 0;
        }
    }

    vector<string> getTopK(int k) {
        vector<string> res;
        for (auto iter = cnts.rbegin(); iter != cnts.rend(); ++iter) {
            auto cnt = *iter;
            for (auto& key : cnt2key[cnt]) {
                res.push_back(key);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};

int main() {
    auto printer = [&](const vector<string>& res) {
        for (const auto& s : res) cout << s << ",";
        cout << "\n";
    };
    TopKElements record;
    record.increment("A");
    record.increment("B");
    record.increment("C");
    printer(record.getTopK(3));
    record.increment("B");
    printer(record.getTopK(2));
    return 0;
}
