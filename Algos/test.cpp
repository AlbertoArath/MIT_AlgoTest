#include <gtest/gtest.h>
#include <gmock/gmock.h>




class SigProvider {
        public:
            virtual ~SigProvider() = default;
            virtual int get_sig() = 0;
    };
// Function to test, takes dependency as parameter
int add_with_sig(int a, int b, SigProvider& sig_provider) {
    return a + b + sig_provider.get_sig();
}
class MockSigProvider : public SigProvider {
    public:
        MOCK_METHOD(int, get_sig, (), (override));
    };

// Test case
// Test
TEST(AdditionTest, AddsWithMockedSig) {
    MockSigProvider mock;

    EXPECT_CALL(mock, get_sig())
        .Times(1)
        .WillOnce(::testing::Return(10));

    int result = add_with_sig(2, 3, mock);
    EXPECT_EQ(result, 15);  // 2 + 3 + 10
}

