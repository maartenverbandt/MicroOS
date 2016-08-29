#include "rate_limiter.h"

RateLimiter::RateLimiter(float rate) :
	_rate(rate),
	_value(0.0f)
{
	//do nothing
}

float RateLimiter::update(float input)
{
	float rate_cmd;
	
	if(input > _value){
		rate_cmd = input - _value;
		if(rate_cmd < _rate){
			_value = input;
		} else {
			_value = _value + _rate;
		}
	}	else {
		rate_cmd = _value - input;
		if(rate_cmd < _rate){
			_value = input;
		} else {
			_value = _value - _rate;
		}
	}
	
	return _value;
}

void RateLimiter::setRate(float rate)
{
	_rate = rate;
}

float RateLimiter::getRate()
{
	return _rate;
}

float RateLimiter::getValue()
{
	return _value;
}
