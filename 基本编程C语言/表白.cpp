#include <iostream>
int main()
{
  std::cout << "你是否知道他也喜欢你？(Y/N)" << std::endl;
  char c = 0;
  bool loveYou = false;
  std::cin >> c;

  if (c == 'Y')
  {
    loveYou = true;
  }
  else
  {
    loveYou = false;
  }

  if (!loveYou)
  {
    std::cout << "这招是没用的，得到的是类似\"谢谢，你是一个很好的女生，我真的"
                 "很感动，但是......最后真的谢谢!\""
              << std::endl;
    std::cout << "画面太美，我不敢看，具体可以打开旁边的网址";
    std::cout << "https://pic1.zhimg.com/0ed4344f448006bbe91864bef6a5cc80_b.png"
              << std::endl;
    std::cout << "告白并不会提升喜欢你的几率，他不喜欢你，告白是没有任何用的。"
              << std::endl;
  }
  else
  {
    std::cout << "直接约出来聊聊天，直接说就好，用什么C++. "
                 "强势一点，走路的时候，直接把手牵住，他那天晚上回到寝室，会"
                 "高兴的跳舞。"
              << std::endl;
  }
}
