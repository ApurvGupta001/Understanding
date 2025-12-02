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

    int getQuestionId() const { return questionId; }
    const string& getQuestionText() const { return questionText; }
    const vector<string>& getQuestionTags() const { return questionTags; }
    User* getAuthor() const { return author; }
    void setAuthor(User* a) { author = a; }
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
        getUserId(++userIdCounter); // Increment user ID counter
        User *newUser = new User(userIdCounter, name, email);
        users.push_back(*newUser);
        return newUser;
    }

    Question* addQuestion(const string& text, User* author) {
        getQuestionId(++questionIdCounter); // Increment question ID counter
        Question *newQuestion = new Question(questionIdCounter, text, author);
        questions.push_back(*newQuestion);
        return newQuestion;
    }
    void showUsers() const {
        for (const auto& user : users) {
            cout << "User ID: " << user.getUserId()
                 << ", Name: " << user.getUserName()
                 << ", Email: " << user.getUserEmail() << '\n';
        }
    }

    void showQuestions() const {
        
        for (const auto& question : questions) {
            cout << "author: " << question.getAuthor()->getUserName() << '\n';
            cout << "Question ID: " << question.getQuestionId()
                 << ", Text: " << question.getQuestionText() << '\n';
        }
    }

    string getUserId (int id) {
        return 'U' + to_string(id);
    }

    string getQuestionId (int id) {
        return 'Q' + to_string(id);
    }

    string getAnswerId (int id) {
        return 'A' + to_string(id);
    }
};

int main() {
    StackOverflow SO;
    User* user1 = SO.addUser("Alice", "alice@example.com");
    User* user2 = SO.addUser("Bob", "bob@example.com");

    SO.addQuestion("What is C++?", user1);
    SO.addQuestion("How to use vectors in C++?", user2);

    cout << "All questions:\n";
    SO.showQuestions();

    cout << "\nAll users:\n";
    SO.showUsers();
    return 0;
}
