/*----------------------------------------------------------------------------
 *
 * subdomain_visit_count.cc
 *   A website domain like "discuss.leetcode.com" consists of various
 *   subdomains. At the top level, we have "com", at the next level, we
 *   have "leetcode.com", and at the lowest level,
 *   "discuss.leetcode.com". When we visit a domain like
 *   "discuss.leetcode.com", we will also visit the parent domains
 *   "leetcode.com" and "com" implicitly.
 *
 *   Now, call a "count-paired domain" to be a count (representing the
 *   number of visits this domain received), followed by a space,
 *   followed by the address. An example of a count-paired domain might
 *   be "9001 discuss.leetcode.com".
 *
 *   We are given a list `cpdomains` of count-paired domains. We would
 *   like a list of count-paired domains, (in the same format as the
 *   input, and in any order), that explicitly counts the number of
 *   visits to each subdomain.
 *
 *----------------------------------------------------------------------------
 */
class Solution {
public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        unordered_map<string, int> ht;
        vector<string> result;

        for (auto cpdomain : cpdomains) {
            int count = 0;
            split(cpdomain, count);
            add(cpdomain, ht, count);
        }

        for (const auto &domain: ht) {
            string s = to_string(domain.second) + " " + domain.first;
            result.push_back(s);
        }

        return result;
    }

private:
    void split(string &sentence, int &val) {
        int v = 0;
        size_t len = sentence.length();
        string::size_type pos = sentence.find(' ');
        val = stoi(sentence.substr(0, pos), NULL, 10);
        sentence = sentence.substr(pos + 1);
    }

    void add(string &sentence, unordered_map<string, int> &ht, int val) {
        if (ht.find(sentence) != ht.end()) {
            ht[sentence] += val;
        } else {
            ht[sentence] = val;
        }

        string::size_type pos = sentence.find('.');
        while (pos != string::npos) {
            string subdomain = sentence.substr(pos + 1);
            if (ht.find(subdomain) != ht.end()) {
                cout <<val <<endl;
                ht[subdomain] += val;
            } else {
                ht[subdomain] = val;
            }
            pos = sentence.find('.', pos + 1);
        }
    }
};
