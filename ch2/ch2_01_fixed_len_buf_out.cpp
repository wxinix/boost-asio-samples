#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main()
{
  // Step 1 and 2 in single line.
  // 'buf' is the raw buffer. Note the "const-ness".
  const std::string buf{"Hello"};

  // Step 3. Creating buffer representation that satisfies
  // ConstBufferSequence concept requirements.
  asio::const_buffers_1 output_buf = asio::buffer(buf);

  // Step 4. 'output_buf' is the representation of the
  // buffer 'buf' that can be used in Boost.Asio output
  // operations.

  return 0;
}
