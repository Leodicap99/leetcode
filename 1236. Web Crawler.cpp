/*
I ll just tell u what the question asks briefly:
You have a class HtmlParser like this:-

class HtmlParser {
    public:
      vector<string> getUrls(string url);
 };

 The question asks if I have a startingt Url say "http://news.yahoo.com/news/topics/" return all the Urls having that share the same hostname.

 Let urls = [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.google.com",
  "http://news.yahoo.com/us"
]

 Then ur function must return:-
  [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.yahoo.com/us"
]
Notice that all of them have the same hostname "http://news.yahoo.com".

They have given a hint in the question that u shouldnt visit a website multiple time which means it should be a graph traversal question.

I will be using BFS to solve this question.

We dont want duplication of data so I will be using a set to help me tackle this problem

I will first extract the start url hostname by :-
string hostname=startUrl.substr(0,startUrl.find('/',7));
                                    ^
                                    |

                                    This helps me get the url from start to the first / u see after the 7th poistion as http:// has 7 charcters and we need them for our hostname.

We push the start Url into the q and traverse all of its urls that htmlparser gives us and push all the website having the same hostname into the queue to help us crawl.

*/
    string gethost(string url)
    {
        return url.substr(0,url.find('/',7));
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        const string hostname=startUrl.substr(0,startUrl.find('/',7));
        unordered_set<string> s;
        queue<string> q;
        q.push(startUrl);
        while(!q.empty())
        {
            string t=q.front();
            q.pop();
            s.insert(t);
            for(auto x:htmlParser.getUrls(t))
            {
                string check=gethost(x);
                if(s.find(x)==s.end() && check==hostname)
                {
                    q.push(x);
                }
            }
        }
        vector<string> ans(s.begin(),s.end());
        return ans;
    }