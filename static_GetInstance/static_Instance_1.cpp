
#include <iostream>

using namespace std;

class SXM360Service {
private:
      SXM360Service();
      ~SXM360Service();
public:
      static SXM360Service &GetInstance();
private:
      static SXM360Service *mInstance;
};

// implement
SXM360Service *SXM360Service::mInstance = NULL;

SXM360Service::SXM360Service() {
      cout << "SXM360Service()" << endl;
}

SXM360Service::~SXM360Service() {
      cout << "~SXM360Service()" << endl;
}

SXM360Service &SXM360Service::GetInstance() {   // 返回的时引用,不是指针
      if (NULL == mInstance) {
            mInstance = new SXM360Service();
      }

      return *mInstance;   // 所以这个地方不能直接返回 指针(mInstance)
}

int main(int argc, char const *argv[])
{
      SXM360Service &s1 = SXM360Service::GetInstance();
      SXM360Service &s2 = SXM360Service::GetInstance();
      if (SXM360Service &s1 == SXM360Service &s2) {
            cout << "s1 == s2" << endl;
      }

      return 0;
}
