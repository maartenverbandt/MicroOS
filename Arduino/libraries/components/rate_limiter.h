#ifndef RATE_LIMITER_H
#define RATE_LIMITER_H

class RateLimiter
{
private:
	float _rate;
	float _value;	
	
public:
	RateLimiter(float rate = 0.0f);
	
	float update(float input);
	
	void setRate(float rate);
	float getRate();
	float getValue();
};

#endif //RATE_LIMITER_H 
