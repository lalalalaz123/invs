#pragma once

#include <cstdint>

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 300; // seconds
const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x166df9; //
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 60;
const size_t   CRYPTONOTE_TX_SPENDABLE_AGE                   = 6;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V1         = 60 * 60 * 2;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V1          = 60;

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY                                  = UINT64_C(261800000000);
const uint64_t COIN                                          = UINT64_C(100);
const uint64_t TAIL_EMISSION_REWARD                          = UINT64_C(100);
const size_t CRYPTONOTE_COIN_VERSION                         = 1;
const unsigned EMISSION_SPEED_FACTOR                         = 26;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 10000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 10000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 10000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 2;

const uint64_t MINIMUM_FEE_V1                                = 01;
const uint64_t MINIMUM_FEE_V2                                = 01;
const uint32_t MINIMUM_FEE_V2_HEIGHT                         = 11833;
const uint64_t MINIMUM_FEE                                   = MINIMUM_FEE_V2;
const uint64_t MAXIMUM_FEE                                   = 01;

const uint64_t DEFAULT_DUST_THRESHOLD                        = MINIMUM_FEE;
const uint64_t MIN_TX_MIXIN_SIZE                             = 2;
const uint64_t MAX_TX_MIXIN_SIZE_V1                          = 10;
const uint64_t MAX_TX_MIXIN_SIZE_V2                          = 10;
const uint64_t MAX_TX_MIXIN_SIZE                             = MAX_TX_MIXIN_SIZE_V2;
const uint32_t MIN_TX_MIXIN_V1_HEIGHT                        = 11800;
const uint32_t MIN_TX_MIXIN_V2_HEIGHT                        = 11800;
const uint64_t MAX_TRANSACTION_SIZE_LIMIT                    = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT / 4 - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE;;

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_WINDOW_V2                          = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const size_t   DIFFICULTY_WINDOW_V3                          = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;  // !!!
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

static constexpr uint64_t POISSON_CHECK_TRIGGER = 10; // Reorg size that triggers poisson timestamp check
static constexpr uint64_t POISSON_CHECK_DEPTH = 60;   // Main-chain depth of the poisson check. The attacker will have to tamper 50% of those blocks
static constexpr double POISSON_LOG_P_REJECT = -75.0; // Reject reorg if the probablity that the timestamps are genuine is below e^x, -75 = 10^-33

const size_t   MAX_BLOCK_SIZE_INITIAL                        = 20 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1 * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t UPGRADE_HEIGHT_V2                             = 11831;
const uint32_t UPGRADE_HEIGHT_V3                             = 11831;
const uint32_t UPGRADE_HEIGHT_V4                             = 11831;
const uint32_t UPGRADE_HEIGHT_V5                             = 11831;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90; // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "investcoin";
const char     GENESIS_COINBASE_TX_HEX[]                     = "013c01ff000101029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121019093d7a8a8187801a8b1adceff6da28b359f070dc3e60292179fc5ca4bf8b92d";

const uint8_t  CURRENT_TRANSACTION_VERSION                   =  1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  200;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  5333;
const int      RPC_DEFAULT_PORT                              =  5334;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 16 * 1024 * 1024; // 16 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const uint32_t P2P_FAILED_ADDR_FORGET_SECONDS                = (60 * 60);     //1 hour
const uint32_t P2P_IP_BLOCKTIME                              = (60 * 60 * 24);//24 hour
const uint32_t P2P_IP_FAILS_BEFORE_BLOCK                     = 10;
const uint32_t P2P_IDLE_CONNECTION_KILL_INTERVAL             = (5 * 60);      //5 minutes

const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "04cc9e9502ff480ba0c48e7acf2188cbaea1e734b442e5b4e6de36953b0805ee81b6bf5e48e67df32295fd72610ba3e90319ac4ce38b0f2c017323c933c923432b";

const char* const SEED_NODES[] = { 
  "81.177.135.60:5333"
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = { 
  {10,		"3f658b2dacdd0c1bc1c3cc59037a867992c688079cf5a6594567e2d66b2eb4f1" },
  {100,		"cc5133a55eac068fbbe512dab52b62d6dc5486a0c4da03f5389da8422b2e967c" },
  {1000,	"dece7c338cb084377748106548bfcc14d50c1a7d20e98435a1118c81db3c86fb" },
  {10000,	"7a296132cca0c2e550a824c7997e9a129d019d1e87512e3959c0f86568521932" },
  {11832, 	"a24f5db484e7297b81f98b575304c6f24587ed1f01d65953ad8565361b827620" }
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS



