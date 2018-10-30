#ifndef PROJECT2_GROUP_H
#define PROJECT2_GROUP_H

#include <ostream>

using namespace std;

class Group{
public:
    char *getSpecialRequirements() const;
    void setSpecialRequirements(char *specialRequirements);
    int getSize() const;
    void setSize(int size);
    bool isInterestedInPromotions() const;
    void setInterestedInPromotions(bool interestedInPromotions);
    char *getContactName() const;
    void setContactName(char *contactName);
    char *getContactEmail() const;
    void setContactEmail(char *contactEmail);
    ~Group();
    Group(){
    }
    Group(char*, char*);
    Group& operator=(const Group&);
    Group(const Group&);
    friend ostream & operator<<(ostream &, const Group&);
private:
    bool interestedInPromotions;
    char * contactName = nullptr;
    char * contactEmail = nullptr;
    char * specialRequirements = nullptr;
    int size;
};

#endif //PROJECT2_GROUP_H
