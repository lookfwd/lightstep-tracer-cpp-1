#pragma once

#include <event2/event.h>
#include <opentracing/span.h>
#include <memory>
#include <string>
#include <vector>

class QASession {
 public:
  QASession(std::unique_ptr<opentracing::Span>&& span, evutil_socket_t socketfd,
            event_base* base);

  ~QASession();

 private:
  std::unique_ptr<opentracing::Span> span_;
  event* event_;
  std::string active_question_;
  std::string active_answer_;
  std::string answers_;
  size_t write_index_ = 0;

  static void EventCallback(evutil_socket_t socketfd, short what,
                            void* context);

  void ReadQuestions(evutil_socket_t socketfd);

  void WriteAnswers(evutil_socket_t socketfd);
};
