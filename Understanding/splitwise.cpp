#include <iostream>
#include <vector>
using namespace std;

class User {
private:
    int userId;
    string userName;

public:
    User(int id, string name) : userId(id), userName(name) {}

    int getUserId() const { return userId; }
    string getUserName() const { return userName; }
};

class Group {
private:
    int groupId;
    string groupName;
    vector<User*> participants;

public:
    Group(int id, string name) : groupId(id), groupName(name) {}

    void addParticipants(User *user) {
        participants.push_back(user);
    }

    void printGroupDetails() {
        cout << "Group ID: " << groupId << ", Group Name: " << groupName << endl;
        cout << "Participants: " << endl;
        for (auto user : participants) {
            cout << "User ID: " << user->getUserId() << ", User Name: " << user->getUserName() << endl;
        }
    }
};

int main() {
    // Create Users 
    User user1(1, "Alice");
    User user2(2, "Bob");
    User user3(3, "Charlie");

    // Create a Group
    Group group1(101, "Developers");

    // Add participants to the group
    group1.addParticipants(&user1);
    group1.addParticipants(&user2);
    group1.addParticipants(&user3);

    // Print group details
    group1.printGroupDetails();

    return 0;
}
