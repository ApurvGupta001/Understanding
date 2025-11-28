#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
private:
    int userId;
    string userName;
    string userEmail;
public:
    User(int id, const string& name, const string& email)
        : userId(id), userName(name), userEmail(email) {}

    int getUserId() const { return userId; }
    const string& getUserName() const { return userName; }
    const string& getUserEmail() const { return userEmail; }
};

class Question {
private:
    int questionId;
    string questionText;
    vector<string> questionTags;
    User* author;
public:
    // Minimal constructor (not used in this example)
    Question(int id = 0, const string& text = "", User* a = nullptr)
        : questionId(id), questionText(text), author(a) {}
};

class StackOverflow {
private:
    vector<User> users;
    vector<string> tags;
    vector<Question> questions;
    vector<string> answers;
    int userIdCounter;
    int questionIdCounter;
public:
    StackOverflow() : userIdCounter(0), questionIdCounter(0) {}

    // Adds a user and returns a pointer to the stored user.
    // NOTE: pointer remains valid until 'users' is reallocated (on further insertions that cause growth).
    User* addUser(const string& name, const string& email) {
        ++userIdCounter;
        users.emplace_back(userIdCounter, name, email);
        return &users.back();
    }

    void showUsers() const {
        for (const auto& user : users) {
            cout << "User ID: " << user.getUserId()
                 << ", Name: " << user.getUserName()
                 << ", Email: " << user.getUserEmail() << '\n';
        }
    }
};

int main() {
    StackOverflow SO;
    User* user1 = SO.addUser("Alice", "alice@example.com");
    User* user2 = SO.addUser("Bob", "bob@example.com");

    // Demonstrate returned pointers are usable (safe here because no further insertions happen after these)
    cout << "Pointer info:\n";
    if (user1) cout << "user1 -> " << user1->getUserName() << '\n';
    if (user2) cout << "user2 -> " << user2->getUserEmail() << '\n';

    cout << "\nAll users:\n";
    SO.showUsers();
    return 0;
}
