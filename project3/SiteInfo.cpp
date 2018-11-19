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

char *SiteInfo::getName() const {
    return name;
}

void SiteInfo::setName(char *_name) {
    if(_name){
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
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

SiteInfo::SiteInfo(char *topic, char **info) {
    setTopic(topic);
    setName(info[0]);
    setAddress(info[1]);
    setRating(atoi(info[2]));
    setReview(info[3]);
    setSummary(info[4]);

}

SiteInfo::~SiteInfo(){
    delete[] name;
    delete[] address;
    delete[] summary;
    delete[] review;
    delete[] topic;
}

ostream &operator<<(ostream &out, const SiteInfo &info) {
    out << "Topic: " << info.getTopic() << endl
         << "Name: " << info.getName() << endl
         << "Rating: " << info.getRating() << endl
         << "Review: " << info.getReview() << endl
         << "Summary: " << info.getSummary() << endl;
    return out;
}

SiteInfo::SiteInfo(const SiteInfo &info) {
    setName(info.name);
    setReview(info.review);
    setSummary(info.summary);
    setRating(info.rating);
    setAddress(info.address);
    setTopic(info.topic);
}

SiteInfo & SiteInfo::operator=(const SiteInfo& info) {
    setName(info.name);
    setReview(info.review);
    setSummary(info.summary);
    setRating(info.rating);
    setAddress(info.address);
    setTopic(info.topic);
    return *this;
}