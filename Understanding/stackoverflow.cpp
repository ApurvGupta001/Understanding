#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------- USER ----------
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

// ---------- QUESTION ----------
class Question {
private:
    int questionId;
    string questionText;
    vector<string> questionTags;
    int authorId;
public:
    Question(int id = 0, const string& text = "", int authId = 0)
        : questionId(id), questionText(text), authorId(authId) {}

    int getQuestionId() const { return questionId; }
    const string& getQuestionText() const { return questionText; }
    const vector<string>& getQuestionTags() const { return questionTags; }
    int getAuthorId() const { return authorId; }
    void setAuthor(int id) { authorId = id; }
};

// ---------- ANSWER ----------
class Answer {
private:
    int answerId;
    int questionId;
    string answerText;
    int authorId;
public:
    Answer(int id = 0, const string& text = "", int qId = 0, int aId = 0)
        : answerId(id), answerText(text), questionId(qId), authorId(aId) {}

    int getAnswerId() const { return answerId; }
    const string& getAnswerText() const { return answerText; }
    int getAuthorId() const { return authorId; }
    int getQuestionId() const { return questionId; }
    void setAuthor(int a) { authorId = a; }
};

// ---------- STACKOVERFLOW ----------
class StackOverflow {
private:
    vector<User> users;
    vector<Question> questions;
    vector<Answer> answers;
    int userIdCounter;
    int questionIdCounter;
    int answerIdCounter;

public:
    StackOverflow() : userIdCounter(0), questionIdCounter(0), answerIdCounter(0) {}

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

    Answer* addAnswer (const string& text, Question* question, User* author) {
        getAnswerId(++answerIdCounter); // Increment answer ID counter
        Answer *newAnswer = new Answer(answerIdCounter, text, question, author);
        answers.push_back(*newAnswer);
        return newAnswer;
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
            cout << "Author ID: " << question.getAuthorId() << '\n';
            cout << "Question ID: " << question.getQuestionId()
                 << ", Text: " << question.getQuestionText() << '\n';
        }
    }

    void showAnswers() const {
        for (const auto& answer : answers) {
            cout << "Author ID: " << answer.getAuthorId() << '\n';
            cout << "Answer ID: " << answer.getAnswerId()
                 << ", Text: " << answer.getAnswerText() << '\n';
        }
    }
};

// ---------- MAIN ----------
int main() {
    StackOverflow SO;

    User* user1 = SO.addUser("Alice", "alice@example.com");
    User* user2 = SO.addUser("Bob", "bob@example.com");

    Question* q1 = SO.addQuestion("What is C++?", user1);
    Question* q2 = SO.addQuestion("How to use vectors in C++?", user2);

    SO.addAnswer("C++ is a general-purpose programming language.", q1, user2);
    SO.addAnswer("Use std::vector<T> and its push_back method.", q2, user1);

    cout << "\nAll answers:\n";
    SO.showAnswers();

    cout << "\nAll questions:\n";
    SO.showQuestions();

    cout << "\nAll users:\n";
    SO.showUsers();
}
