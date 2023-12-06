#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Post {
    string title;
    string content;
    string author;
};

class Blog {
private:
    vector<Post> posts;

public:
    void createPost() {
        Post newPost;
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, newPost.title);
        cout << "Enter content: ";
        getline(cin, newPost.content);
        cout << "Enter author: ";
        getline(cin, newPost.author);

        posts.push_back(newPost);

        ofstream file("C:\\Users\\umbar\\OneDrive\\Documents\\Desktop\\python\\blog_posts.txt", ios::app);
        if (file.is_open()) {
            file << newPost.title << endl;
            file << newPost.content << endl;
            file << newPost.author << endl;
            file << "----\n";
            file.close();
            cout << "Post created successfully!\n";
        } else {
            cout << "Unable to open file!\n";
        }
    }

    void displayAllPosts() {
        ifstream file("C:\\Users\\umbar\\OneDrive\\Documents\\Desktop\\python\\blog_posts.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file!\n";
        }
    }
};

int main() {
    Blog myBlog;
    int choice;

    do {
        cout << "\nBlog Management System\n";
        cout << "1. Create Post\n";
        cout << "2. Display All Posts\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myBlog.createPost();
                break;
            case 2:
                myBlog.displayAllPosts();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}