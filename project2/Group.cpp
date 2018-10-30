#include <cstring>
#include "Group.h"

int Group::getSize() const {
    return size;
}

void Group::setSize(int size) {
    this->size = size;
}

bool Group::isInterestedInPromotions() const {
    return interestedInPromotions;
}

void Group::setInterestedInPromotions(bool interestedInPromotions) {
    Group::interestedInPromotions = interestedInPromotions;
}

char *Group::getContactName() const {
    return contactName;
}

void Group::setContactName(char *contactName) {
    delete[] Group::contactName;
    Group::contactName = contactName;
}

char *Group::getContactEmail() const {
    return contactEmail;
}

void Group::setContactEmail(char *contactEmail) {
    delete[] Group::contactEmail;
    Group::contactEmail = contactEmail;
}

char *Group::getSpecialRequirements() const {
    return specialRequirements;
}

void Group::setSpecialRequirements(char *specialRequirements) {
    delete[] this->specialRequirements;
    this->specialRequirements = new char[strlen(specialRequirements) + 1];
    strcpy(this->specialRequirements, specialRequirements);
}

Group &Group::operator=(const Group &group) {
    this->contactName = new char[strlen(group.contactName) + 1];
    strcpy(this->contactName, group.contactName);
    this->contactEmail = group.contactEmail;
    this->contactEmail = new char[strlen(group.contactEmail) + 1];
    strcpy(this->contactEmail, group.contactEmail);
    this->specialRequirements = new char[strlen(group.specialRequirements) + 1];
    strcpy(this->specialRequirements, group.specialRequirements);
    this->size = group.size;
    this->interestedInPromotions = group.interestedInPromotions;
    return *this;
}

Group::~Group() {
    delete[] contactName;
    delete[] contactEmail;
    delete[] specialRequirements;
}

Group::Group(char * name, char * email) {
    contactName = new char[strlen(name) + 1];
    strcpy(contactName, name);
    contactEmail = email;
    contactEmail = new char[strlen(email) + 1];
    strcpy(contactEmail, email);
}

ostream &operator<<(ostream &out, const Group &group) {
    out << "Name: " << group.getContactName() << endl
        << "Email: " << group.getContactEmail() << endl
        << "People: " << group.getSize() << endl
        << "Special Requirements: " << group.getSpecialRequirements() << endl;
    return out;
}

Group::Group(const Group &group) {
    this->contactName = new char[strlen(group.contactName) + 1];
    strcpy(this->contactName, group.contactName);
    this->contactEmail = group.contactEmail;
    this->contactEmail = new char[strlen(group.contactEmail) + 1];
    strcpy(this->contactEmail, group.contactEmail);
    this->specialRequirements = new char[strlen(group.specialRequirements) + 1];
    strcpy(this->specialRequirements, group.specialRequirements);
    this->size = group.size;
    this->interestedInPromotions = group.interestedInPromotions;
}
