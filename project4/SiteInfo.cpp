#include <cstdlib>
#include <cstring>
#include "SiteInfo.h"

void SiteInfo::setTopic(char *_topic) {
    if(_topic){
        topic = new char[strlen(_topic) + 1];
        strcpy(topic, _topic);
    }
}

char *SiteInfo::getTopic() const {
    return topic;
}

char *SiteInfo::getKeyword() const {
    return keyword;
}

void SiteInfo::setKeyword(char *_keyword) {
    if(_keyword){
        keyword = new char[strlen(_keyword) + 1];
        strcpy(keyword, _keyword);
    }
}

char *SiteInfo::getAddress() const {
    return address;
}

void SiteInfo::setAddress(char *_address) {
    if(_address){
        address = new char[strlen(_address) + 1];
        strcpy(address, _address);
    }
}

int SiteInfo::getRating() const {
    return rating;
}

void SiteInfo::setRating(int _rating) {
    rating = _rating;
}

char *SiteInfo::getReview() const {
    return review;
}

void SiteInfo::setReview(char *_review) {
    if(_review){
        review = new char[strlen(_review) + 1];
        strcpy(review, _review);
    }
}

char *SiteInfo::getSummary() const {
    return summary;
}

void SiteInfo::setSummary(char *_summary) {
    if(_summary){
        summary = new char[strlen(_summary) + 1];
        strcpy(summary, _summary);
    }
}

SiteInfo::SiteInfo(char **info) {
    setTopic(info[0]);
    setKeyword(info[1]);
    setAddress(info[2]);
    setRating(atoi(info[3]));
    setReview(info[4]);
    setSummary(info[5]);

}

SiteInfo::~SiteInfo(){
    delete[] keyword;
    delete[] address;
    delete[] summary;
    delete[] review;
    delete[] topic;
}

ostream &operator<<(ostream &out, const SiteInfo &info) {
    out << "Topic: " << info.getTopic() << endl
         << "Name: " << info.getKeyword() << endl
         << "Rating: " << info.getRating() << endl
         << "Review: " << info.getReview() << endl
         << "Summary: " << info.getSummary() << endl;
    return out;
}

SiteInfo::SiteInfo(const SiteInfo &info) {
    setKeyword(info.keyword);
    setReview(info.review);
    setSummary(info.summary);
    setRating(info.rating);
    setAddress(info.address);
    setTopic(info.topic);
}

SiteInfo & SiteInfo::operator=(const SiteInfo& info) {
    setKeyword(info.keyword);
    setReview(info.review);
    setSummary(info.summary);
    setRating(info.rating);
    setAddress(info.address);
    setTopic(info.topic);
    return *this;
}