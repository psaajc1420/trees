//
// Created by jacob on 11/13/21.
//

#include "timer.h"

void Timer::Start() {
  start_time_ = system_clock::now();
  is_running_ = true;
}

void Timer::Stop() {
  end_time_ = system_clock::now();
  is_running_ = false;
}

double Timer::ElapsedNanoSeconds() {
  time_point<system_clock> end_time;
  end_time = is_running_ ? system_clock::now() : end_time_;
  return duration_cast<nanoseconds>(end_time-start_time_).count();
}

double Timer::ElapsedSeconds() {
  return ElapsedNanoSeconds() / 1e9;
}