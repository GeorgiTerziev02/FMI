// Very very basic implementation of a Singleton design pattern

#include <mutex>

class Singleton {
	static Singleton* instance;
	static std::mutex mutex_;
	Singleton() {}

public:
	Singleton(const Singleton&) = delete;
	void operator=(const Singleton&) = delete;

	static Singleton* getInstance();
};

Singleton* Singleton::instance(nullptr);
std::mutex Singleton::mutex_;

Singleton* Singleton::getInstance() {
	std::lock_guard<std::mutex> lock(mutex_);
	if (instance == nullptr)
		instance = new Singleton();

	return instance;
}