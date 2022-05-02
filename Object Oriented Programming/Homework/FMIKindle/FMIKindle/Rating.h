#pragma once
class Rating
{
private:
	char* userName;
	unsigned short rating;
public:
	Rating();
	Rating(const char* userName, const unsigned short rating);
	Rating(const Rating&);
	Rating& operator=(const Rating&);
	~Rating();

	const char* getUserName() const;
	unsigned short getRating() const;

	void setRating(const unsigned short);

private:
	void copy(const Rating&);
	void free();
};

