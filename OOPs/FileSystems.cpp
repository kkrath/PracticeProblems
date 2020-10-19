#include<string>
#include<ctime>
#include<iostream>
#include<set>
using namespace std;

class File;
class Directory;

class Entity {
private:
	string name;
	std::time_t createdOn;
	std::time_t modifiedOn;
	string modifiedBy;
	Directory* parent;
public:

	Entity(string name, string author, Directory* parent) {
		this->name = name;
		this->createdOn = time(NULL);
		this->modifiedOn = time(NULL);;
		this->modifiedBy = author;
		if (parent) {
			this->parent = parent;
			this->parent->addEntity(this);
		}
	}
	string getName() {
		return this->name;
	}
	bool changeName(string newName, string user, string author) {
		if (this->name == newName)
			return false;
		this->name = newName;
		this->modifiedOn = time(NULL);
		this->modifiedBy = author;
		return true;

	}

	Directory* getParent() {
		return this->parent;
	}
	virtual std::size_t size() const = 0;

	void setParent(Directory* newParent) {
		if (this->parent) {
			this->parent->removeEntity(this);
		}
		if ((this->parent = newParent)) {
			this->parent->addEntity(this);
		}
	}
	~Entity() {
		if (this->parent) {
			this->parent->removeEntity(this);
		}
	}


};

class File : public Entity {
private:
	string contents;

public:
	File(string contents, string name, string author, Directory* parent) :Entity{ name, author, parent }, contents{ contents } {};

	std::size_t size() const override
	{
		return this->contents.size();
	}

	string read() {
		return this->contents;
	}
	void write(string contentNew) {
		contents = std::move(contentNew);
	}

};


class Directory : public Entity {

private:
	set<Entity*> children;
public:
	Directory(string name, string author, Directory* parent = nullptr) : Entity{ name, author, parent } {};
	void addEntity(Entity* entity) {
		children.insert(entity);
	}
	void removeEntity(Entity* entity) {
		children.erase(entity);
	}
	std::size_t size() const override
	{
		std::size_t size = 0;
		for (auto child : children) {
			size += child->size();
		}
		return size;
	}
	int numberOfChildren() {
		return children.size();
	}

};


/* Testing the file system */
int main() {
	Directory root{"/","System", nullptr};
	Directory home{ "home", "System", &root };
	Directory liv{ "liv", "System", &root };
	Directory dev{ "dev", "System", &root };
	cout << "Number of children in root " << root.numberOfChildren() << endl;
}