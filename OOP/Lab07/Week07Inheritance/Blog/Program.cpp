#include "iostream"
#include "string"
#include "Post.h"
#include "GraphPost.h"

using namespace std;

auto generateComments() {
	return vector<Comment> {
		Comment("Alice", "Great work."),
			Comment("Bob", "This helps me a lot!."),
			Comment("Charlie", "Thanks for your post."),
	};
}

int main() {
	cout << endl << "----- Post -----" << endl;
	string author = "Jane";
	string title = "3 tips to learn English effectively";
	stringstream content;
	content << "To learn English effectively, you can try these 3 tips.\n"
		<< "1. Practice on a daily basis.\n"
		<< "2. Take time to understand difficult paragraphs.\n"
		<< "3. Try new things everyday.";

	Post p(author, title, content.str());
	cout << p.toString();

	cout << endl << "----- Graph Post -----" << endl;
	auto likes = 5;
	auto comments = generateComments();
	GraphPost gp(author, title, content.str(), likes, comments);
	cout << gp.toString();

	return 0;
}