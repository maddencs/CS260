#ifndef PROJECT3_SITEINFO_H
#define PROJECT3_SITEINFO_H

#include <ostream>

using namespace std;


class SiteInfo {
public:
    char *getKeyword() const;
    void setKeyword(char *_keyword);
    char *getAddress() const;
    void setAddress(char *address);
    int getRating() const;
    void setRating(int rating);
    char *getReview() const;
    void setReview(char *review);
    char *getSummary() const;
    void setSummary(char *summary);
    SiteInfo(){
    };
    SiteInfo(char**);
    SiteInfo(const SiteInfo&);
    ~SiteInfo();
    friend ostream & operator<<(ostream &, const SiteInfo&);
    SiteInfo& operator=(const SiteInfo&);

private:
    char * address = nullptr;
    int rating;
    char * keyword = nullptr;
    char * review = nullptr;
    char * summary = nullptr;
    char * topic = nullptr;
public:
    char *getTopic() const;

    void setTopic(char *topic);

public:
};


#endif //PROJECT3_SITEINFO_H
