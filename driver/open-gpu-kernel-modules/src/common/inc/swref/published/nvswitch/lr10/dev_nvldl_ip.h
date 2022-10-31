/*
 * SPDX-FileCopyrightText: Copyright (c) 2003-2022 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the Software),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef __lr10_dev_nvldl_ip_h__
#define __lr10_dev_nvldl_ip_h__
/* This file is autogenerated.  Do not edit */
#define NV_NVLDL_TOP_LINK_STATE                               0x00000000      /* R--4R */
#define NV_NVLDL_TOP_LINK_STATE_STATE                         7:0             /* R-XVF */
#define NV_NVLDL_TOP_LINK_STATE_STATE_INIT                    0x00000000      /* R---V */
#define NV_NVLDL_TOP_LINK_STATE_STATE_HWCFG                   0x00000001      /* R---V */
#define NV_NVLDL_TOP_LINK_STATE_STATE_SWCFG                   0x00000002      /* R---V */
#define NV_NVLDL_TOP_LINK_STATE_STATE_ACTIVE                  0x00000003      /* R---V */
#define NV_NVLDL_TOP_LINK_STATE_STATE_FAULT                   0x00000004      /* R---V */
#define NV_NVLDL_TOP_LINK_STATE_STATE_SLEEP                   0x00000005      /* R---V */
#define NV_NVLDL_TOP_LINK_STATE_STATE_RCVY_AC                 0x00000008      /* R---V */
#define NV_NVLDL_TOP_LINK_STATE_STATE_RCVY_RX                 0x0000000a      /* R---V */
#define NV_NVLDL_TOP_LINK_STATE_STATE_TRAIN                   0x0000000b      /* R---V */
#define NV_NVLDL_TOP_LINK_STATE_AN0_BUSY                      12:12           /* R-XVF */
#define NV_NVLDL_TOP_LINK_STATE_TL_BUSY                       13:13           /* R-XVF */
#define NV_NVLDL_TOP_LINK_STATE_DBG_SUBSTATE                  31:16           /* R-XVF */
#define NV_NVLDL_TOP_LINK_CHANGE                              0x00000040      /* RW-4R */
#define NV_NVLDL_TOP_LINK_CHANGE_STATUS                       1:0             /* R-XVF */
#define NV_NVLDL_TOP_LINK_CHANGE_STATUS_DONE                  0x00000000      /* R---V */
#define NV_NVLDL_TOP_LINK_CHANGE_STATUS_BUSY                  0x00000001      /* R---V */
#define NV_NVLDL_TOP_LINK_CHANGE_STATUS_FAULT                 0x00000002      /* R---V */
#define NV_NVLDL_TOP_LINK_CHANGE_STATUS_ABORT                 0x00000003      /* R---V */
#define NV_NVLDL_TOP_LINK_CHANGE_ACTION                       3:2             /* -WXVF */
#define NV_NVLDL_TOP_LINK_CHANGE_ACTION_LTSSM_CHANGE          0x00000001      /* -W--V */
#define NV_NVLDL_TOP_LINK_CHANGE_ACTION_LTSSM_FORCE           0x00000003      /* -W--V */
#define NV_NVLDL_TOP_LINK_CHANGE_NEWSTATE                     7:4             /* RWEVF */
#define NV_NVLDL_TOP_LINK_CHANGE_NEWSTATE_INIT                0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_LINK_CHANGE_NEWSTATE_HWCFG               0x00000001      /* RW--V */
#define NV_NVLDL_TOP_LINK_CHANGE_NEWSTATE_SWCFG               0x00000002      /* RW--V */
#define NV_NVLDL_TOP_LINK_CHANGE_NEWSTATE_ACTIVE              0x00000003      /* RW--V */
#define NV_NVLDL_TOP_LINK_CHANGE_NEWSTATE_RCVY_AC             0x00000008      /* RW--V */
#define NV_NVLDL_TOP_LINK_CHANGE_NEWSTATE_FAULT               0x00000004      /* RW--V */
#define NV_NVLDL_TOP_LINK_CHANGE_NEWSTATE_RCVY_RX             0x0000000a      /* RW--V */
#define NV_NVLDL_TOP_LINK_CHANGE_NEWSTATE_SLEEP               0x00000005      /* RW--V */
#define NV_NVLDL_TOP_LINK_CHANGE_NEWSTATE_TRAIN               0x0000000b      /* RW--V */
#define NV_NVLDL_TOP_LINK_CHANGE_OLDSTATE_MASK                19:16           /* RWEVF */
#define NV_NVLDL_TOP_LINK_CHANGE_OLDSTATE_MASK_INIT           0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_LINK_CHANGE_OLDSTATE_MASK_DONTCARE       0x0000000f      /* RW--V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE                           0x00000044      /* RW-4R */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_STATUS                    1:0             /* R-EVF */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_STATUS_DONE               0x00000000      /* R-E-V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_STATUS_BUSY               0x00000001      /* R---V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_STATUS_FAULT              0x00000002      /* R---V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_STATUS_ABORT              0x00000003      /* R---V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_ACTION                    3:2             /* -WEVF */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_ACTION_INIT               0x00000000      /* -WE-V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_ACTION_SLSM_CHANGE        0x00000001      /* -W--V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_ACTION_SLSM_FORCE         0x00000003      /* -W--V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_NEWSTATE                  7:4             /* RWEUF */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_NEWSTATE_HS               0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_NEWSTATE_EIGHTH           0x00000004      /* RW--V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_NEWSTATE_TRAIN            0x00000005      /* RW--V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_NEWSTATE_SAFE             0x00000006      /* RW--V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_NEWSTATE_OFF              0x00000007      /* RW--V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_SUBLINK                   15:12           /* RWEUF */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_SUBLINK_TX                0x00000000      /* RW--V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_SUBLINK_RX                0x00000001      /* RWE-V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_OLDSTATE_MASK             19:16           /* RWEUF */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_OLDSTATE_MASK_INIT        0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_OLDSTATE_MASK_DONTCARE    0x0000000f      /* RW--V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_COUNTDOWN                 31:20           /* RWEUF */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_COUNTDOWN_MAXIMUM         0x0000007f      /* RW--V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_COUNTDOWN_MINIMUM         0x00000008      /* RWE-V */
#define NV_NVLDL_TOP_SUBLINK_CHANGE_COUNTDOWN_IMMEDIATE       0x00000000      /* RW--V */
#define NV_NVLDL_TOP_LINK_TEST                                0x00000048      /* RW-4R */
#define NV_NVLDL_TOP_LINK_TEST_MODE                           0:0             /* RWEVF */
#define NV_NVLDL_TOP_LINK_TEST_MODE_ENABLE                    0x00000001      /* RW--V */
#define NV_NVLDL_TOP_LINK_TEST_MODE_DISABLE                   0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_LINK_TEST_AUTO_HWCFG                     30:30           /* RWEVF */
#define NV_NVLDL_TOP_LINK_TEST_AUTO_HWCFG_ENABLE              0x00000001      /* RW--V */
#define NV_NVLDL_TOP_LINK_TEST_AUTO_HWCFG_DISABLE             0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_LINK_TEST_AUTO_NVHS                      31:31           /* RWEVF */
#define NV_NVLDL_TOP_LINK_TEST_AUTO_NVHS_ENABLE               0x00000001      /* RW--V */
#define NV_NVLDL_TOP_LINK_TEST_AUTO_NVHS_DISABLE              0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR                                     0x00000050      /* RW-4R */
#define NV_NVLDL_TOP_INTR_TX_REPLAY                           0:0             /* RWXVF */
#define NV_NVLDL_TOP_INTR_TX_RECOVERY_SHORT                   1:1             /* RWXVF */
#define NV_NVLDL_TOP_INTR_TX_FAULT_RAM                        4:4             /* RWXVF */
#define NV_NVLDL_TOP_INTR_TX_FAULT_INTERFACE                  5:5             /* RWXVF */
#define NV_NVLDL_TOP_INTR_TX_FAULT_SUBLINK_CHANGE             8:8             /* RWXVF */
#define NV_NVLDL_TOP_INTR_RX_FAULT_SUBLINK_CHANGE             16:16           /* RWXVF */
#define NV_NVLDL_TOP_INTR_RX_FAULT_DL_PROTOCOL                20:20           /* RWXVF */
#define NV_NVLDL_TOP_INTR_RX_SHORT_ERROR_RATE                 21:21           /* RWXVF */
#define NV_NVLDL_TOP_INTR_RX_LONG_ERROR_RATE                  22:22           /* RWXVF */
#define NV_NVLDL_TOP_INTR_RX_ILA_TRIGGER                      23:23           /* RWXVF */
#define NV_NVLDL_TOP_INTR_RX_CRC_COUNTER                      24:24           /* RWXVF */
#define NV_NVLDL_TOP_INTR_LTSSM_FAULT_DOWN                    27:27           /* RWXVF */
#define NV_NVLDL_TOP_INTR_LTSSM_FAULT_UP                      28:28           /* RWXVF */
#define NV_NVLDL_TOP_INTR_LTSSM_PROTOCOL                      29:29           /* RWXVF */
#define NV_NVLDL_TOP_INTR_MINION_REQUEST                      30:30           /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2                                 0x00000054      /* RW-4R */
#define NV_NVLDL_TOP_INTR_SW2_TX_REPLAY                       0:0             /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2_TX_RECOVERY_SHORT               1:1             /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2_TX_FAULT_RAM                    4:4             /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2_TX_FAULT_INTERFACE              5:5             /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2_TX_FAULT_SUBLINK_CHANGE         8:8             /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2_RX_FAULT_SUBLINK_CHANGE         16:16           /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2_RX_FAULT_DL_PROTOCOL            20:20           /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2_RX_SHORT_ERROR_RATE             21:21           /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2_RX_LONG_ERROR_RATE              22:22           /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2_RX_ILA_TRIGGER                  23:23           /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2_RX_CRC_COUNTER                  24:24           /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2_LTSSM_FAULT_DOWN                27:27           /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2_LTSSM_FAULT_UP                  28:28           /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2_LTSSM_PROTOCOL                  29:29           /* RWXVF */
#define NV_NVLDL_TOP_INTR_SW2_MINION_REQUEST                  30:30           /* RWXVF */
#define NV_NVLDL_TOP_INTR_STALL_EN                            0x00000058      /* RW-4R */
#define NV_NVLDL_TOP_INTR_STALL_EN_TX_REPLAY                  0:0             /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_TX_REPLAY_DISABLE          0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_TX_RECOVERY_SHORT          1:1             /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_TX_RECOVERY_SHORT_DISABLE  0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_TX_RECOVERY_SHORT_ENABLE   0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_STALL_EN_TX_FAULT_RAM               4:4             /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_TX_FAULT_RAM_DISABLE       0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_TX_FAULT_RAM_ENABLE        0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_STALL_EN_TX_FAULT_INTERFACE         5:5             /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_TX_FAULT_INTERFACE_DISABLE 0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_TX_FAULT_INTERFACE_ENABLE  0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_STALL_EN_TX_FAULT_SUBLINK_CHANGE    8:8             /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_TX_FAULT_SUBLINK_CHANGE_DISABLE 0x00000000 /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_TX_FAULT_SUBLINK_CHANGE_ENABLE 0x00000001  /* RW--V */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_FAULT_SUBLINK_CHANGE    16:16           /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_FAULT_SUBLINK_CHANGE_DISABLE 0x00000000 /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_FAULT_SUBLINK_CHANGE_ENABLE 0x00000001  /* RW--V */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_FAULT_DL_PROTOCOL       20:20           /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_FAULT_DL_PROTOCOL_DISABLE 0x00000000    /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_FAULT_DL_PROTOCOL_ENABLE 0x00000001     /* RW--V */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_SHORT_ERROR_RATE        21:21           /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_SHORT_ERROR_RATE_DISABLE 0x00000000     /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_SHORT_ERROR_RATE_ENABLE 0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_LONG_ERROR_RATE         22:22           /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_LONG_ERROR_RATE_DISABLE 0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_LONG_ERROR_RATE_ENABLE  0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_ILA_TRIGGER             23:23           /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_ILA_TRIGGER_DISABLE     0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_ILA_TRIGGER_ENABLE      0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_CRC_COUNTER             24:24           /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_CRC_COUNTER_DISABLE     0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_RX_CRC_COUNTER_ENABLE      0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_STALL_EN_LTSSM_FAULT_DOWN           27:27           /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_LTSSM_FAULT_DOWN_DISABLE   0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_LTSSM_FAULT_DOWN_ENABLE    0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_STALL_EN_LTSSM_FAULT_UP             28:28           /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_LTSSM_FAULT_UP_DISABLE     0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_LTSSM_FAULT_UP_ENABLE      0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_STALL_EN_LTSSM_PROTOCOL             29:29           /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_LTSSM_PROTOCOL_DISABLE     0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_LTSSM_PROTOCOL_ENABLE      0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_STALL_EN_MINION_REQUEST             30:30           /* RWEVF */
#define NV_NVLDL_TOP_INTR_STALL_EN_MINION_REQUEST_DISABLE     0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_STALL_EN_MINION_REQUEST_ENABLE      0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN                         0x0000005c      /* RW-4R */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_TX_REPLAY               0:0             /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_TX_REPLAY_DISABLE       0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_TX_RECOVERY_SHORT       1:1             /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_TX_RECOVERY_SHORT_DISABLE 0x00000000    /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_TX_RECOVERY_SHORT_ENABLE 0x00000001     /* RW--V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_TX_FAULT_RAM            4:4             /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_TX_FAULT_RAM_DISABLE    0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_TX_FAULT_RAM_ENABLE     0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_TX_FAULT_INTERFACE      5:5             /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_TX_FAULT_INTERFACE_DISABLE 0x00000000   /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_TX_FAULT_INTERFACE_ENABLE 0x00000001    /* RW--V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_TX_FAULT_SUBLINK_CHANGE 8:8             /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_TX_FAULT_SUBLINK_CHANGE_DISABLE 0x00000000 /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_TX_FAULT_SUBLINK_CHANGE_ENABLE 0x00000001 /* RW--V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_FAULT_SUBLINK_CHANGE 16:16           /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_FAULT_SUBLINK_CHANGE_DISABLE 0x00000000 /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_FAULT_SUBLINK_CHANGE_ENABLE 0x00000001 /* RW--V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_FAULT_DL_PROTOCOL    20:20           /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_FAULT_DL_PROTOCOL_DISABLE 0x00000000 /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_FAULT_DL_PROTOCOL_ENABLE 0x00000001  /* RW--V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_SHORT_ERROR_RATE     21:21           /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_SHORT_ERROR_RATE_DISABLE 0x00000000  /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_SHORT_ERROR_RATE_ENABLE 0x00000001   /* RW--V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_LONG_ERROR_RATE      22:22           /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_LONG_ERROR_RATE_DISABLE 0x00000000   /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_LONG_ERROR_RATE_ENABLE 0x00000001    /* RW--V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_ILA_TRIGGER          23:23           /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_ILA_TRIGGER_DISABLE  0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_ILA_TRIGGER_ENABLE   0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_CRC_COUNTER          24:24           /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_CRC_COUNTER_DISABLE  0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_RX_CRC_COUNTER_ENABLE   0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_LTSSM_FAULT_DOWN        27:27           /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_LTSSM_FAULT_DOWN_DISABLE 0x00000000     /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_LTSSM_FAULT_DOWN_ENABLE 0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_LTSSM_FAULT_UP          28:28           /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_LTSSM_FAULT_UP_DISABLE  0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_LTSSM_FAULT_UP_ENABLE   0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_LTSSM_PROTOCOL          29:29           /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_LTSSM_PROTOCOL_DISABLE  0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_LTSSM_PROTOCOL_ENABLE   0x00000001      /* RW--V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_MINION_REQUEST          30:30           /* RWEVF */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_MINION_REQUEST_DISABLE  0x00000000      /* RWE-V */
#define NV_NVLDL_TOP_INTR_NONSTALL_EN_MINION_REQUEST_ENABLE   0x00000001      /* RW--V */
#define NV_NVLDL_TOP_ERROR_COUNT_CTRL                         0x00000080      /* -W-4R */
#define NV_NVLDL_TOP_ERROR_COUNT_CTRL_CLEAR_RECOVERY          2:2             /* -WXVF */
#define NV_NVLDL_TOP_ERROR_COUNT_CTRL_CLEAR_RECOVERY_CLEAR    0x00000001      /* -W--V */
#define NV_NVLDL_TX_TRAIN0_TX                                 0x00002018      /* RW-4R */
#define NV_NVLDL_TX_TRAIN0_TX_PRBS_LEN_0                      10:0            /* RWEVF */
#define NV_NVLDL_TX_TRAIN0_TX_PRBS_LEN_0_INIT                 0x00000260      /* RWE-V */
#define NV_NVLDL_TX_TRAIN0_TX_PRBS_LEN_0_MINIMUM              0x00000001      /* RW--V */
#define NV_NVLDL_TX_TRAIN0_TX_PRBS_LEN_0__PROD_ISSC           0x00000648      /* RW--V */
#define NV_NVLDL_TX_TRAIN0_TX_PRBS_LEN_0_SCL                  15:11           /* RWEVF */
#define NV_NVLDL_TX_TRAIN0_TX_PRBS_LEN_0_SCL_INIT             0x00000004      /* RWE-V */
#define NV_NVLDL_TX_TRAIN0_TX_PRBS_LEN_0_SCL_MINIMUM          0x00000000      /* RW--V */
#define NV_NVLDL_TX_TRAIN0_TX_PRBS_LEN_0_SCL__PROD_ISSC       0x00000005      /* RW--V */
#define NV_NVLDL_TX_TRAIN0_TX_PRBS_INFINITE                   31:31           /* RWEVF */
#define NV_NVLDL_TX_TRAIN0_TX_PRBS_INFINITE_OFF               0x00000000      /* RWE-V */
#define NV_NVLDL_TX_TRAIN0_TX_PRBS_INFINITE_ON                0x00000001      /* RW--V */
#define NV_NVLDL_TX_SLSM_STATUS_TX                            0x00002024      /* R--4R */
#define NV_NVLDL_TX_SLSM_STATUS_TX_SUBSTATE                   3:0             /* R-XVF */
#define NV_NVLDL_TX_SLSM_STATUS_TX_SUBSTATE_STABLE            0x00000000      /* R---V */
#define NV_NVLDL_TX_SLSM_STATUS_TX_PRIMARY_STATE              7:4             /* R-XVF */
#define NV_NVLDL_TX_SLSM_STATUS_TX_PRIMARY_STATE_HS           0x00000000      /* R---V */
#define NV_NVLDL_TX_SLSM_STATUS_TX_PRIMARY_STATE_EIGHTH       0x00000004      /* R---V */
#define NV_NVLDL_TX_SLSM_STATUS_TX_PRIMARY_STATE_TRAIN        0x00000005      /* R---V */
#define NV_NVLDL_TX_SLSM_STATUS_TX_PRIMARY_STATE_SAFE         0x00000006      /* R---V */
#define NV_NVLDL_TX_SLSM_STATUS_TX_PRIMARY_STATE_OFF          0x00000007      /* R---V */
#define NV_NVLDL_TX_SLSM_STATUS_TX_PRIMARY_STATE_UNKNOWN      0x0000000d      /* R---V */
#define NV_NVLDL_TX_ERROR_COUNT_CTRL                          0x00002280      /* -W-4R */
#define NV_NVLDL_TX_ERROR_COUNT_CTRL_CLEAR_REPLAY             8:8             /* -WXVF */
#define NV_NVLDL_TX_ERROR_COUNT_CTRL_CLEAR_REPLAY_CLEAR       0x00000001      /* -W--V */
#define NV_NVLDL_RX_CONFIG_RX                                 0x00003000      /* RW-4R */
#define NV_NVLDL_RX_CONFIG_RX_HW_POLARITY_INVERT              3:0             /* R-EVF */
#define NV_NVLDL_RX_CONFIG_RX_HW_POLARITY_INVERT_NONE         0x00000000      /* R-E-V */
#define NV_NVLDL_RX_CONFIG_RX_HW_POLARITY_INVERT_ALL          0x0000000f      /* R---V */
#define NV_NVLDL_RX_CONFIG_RX_FIFO_WR_REQ_DELAY               7:4             /* RWEVF */
#define NV_NVLDL_RX_CONFIG_RX_FIFO_WR_REQ_DELAY_INIT          0x0000000a      /* RWE-V */
#define NV_NVLDL_RX_CONFIG_RX_HW_LANE_REVERSE                 8:8             /* R-EVF */
#define NV_NVLDL_RX_CONFIG_RX_HW_LANE_REVERSE_OFF             0x00000000      /* R-E-V */
#define NV_NVLDL_RX_CONFIG_RX_HW_LANE_REVERSE_ON              0x00000001      /* R---V */
#define NV_NVLDL_RX_CONFIG_RX_POLARITY_INVERT                 19:16           /* RWEVF */
#define NV_NVLDL_RX_CONFIG_RX_POLARITY_INVERT_NONE            0x00000000      /* RWE-V */
#define NV_NVLDL_RX_CONFIG_RX_POLARITY_INVERT_ALL             0x0000000f      /* RW--V */
#define NV_NVLDL_RX_CONFIG_RX_ECC_MODE                        23:22           /* RWEVF */
#define NV_NVLDL_RX_CONFIG_RX_ECC_MODE_OFF                    0x00000000      /* RWE-V */
#define NV_NVLDL_RX_CONFIG_RX_ECC_MODE_ECC96                  0x00000001      /* RW--V */
#define NV_NVLDL_RX_CONFIG_RX_ECC_MODE_ECC88                  0x00000002      /* RW--V */
#define NV_NVLDL_RX_CONFIG_RX_LANE_REVERSE                    24:24           /* RWEVF */
#define NV_NVLDL_RX_CONFIG_RX_LANE_REVERSE_OFF                0x00000000      /* RWE-V */
#define NV_NVLDL_RX_CONFIG_RX_LANE_REVERSE_ON                 0x00000001      /* RW--V */
#define NV_NVLDL_RX_CONFIG_RX_IOBIST_EN                       25:25           /* RWEVF */
#define NV_NVLDL_RX_CONFIG_RX_IOBIST_EN_OFF                   0x00000000      /* RWE-V */
#define NV_NVLDL_RX_CONFIG_RX_IOBIST_EN_ON                    0x00000001      /* RW--V */
#define NV_NVLDL_RX_CONFIG_RX_PHY_NO_ADJUST                   26:26           /* RWEVF */
#define NV_NVLDL_RX_CONFIG_RX_PHY_NO_ADJUST_OFF               0x00000000      /* RWE-V */
#define NV_NVLDL_RX_CONFIG_RX_PHY_NO_ADJUST_ON                0x00000001      /* RW--V */
#define NV_NVLDL_RX_CONFIG_RX_PHY_ADJUST_OVERRIDE             27:27           /* RWEVF */
#define NV_NVLDL_RX_CONFIG_RX_PHY_ADJUST_OVERRIDE_OFF         0x00000000      /* RWE-V */
#define NV_NVLDL_RX_CONFIG_RX_PHY_ADJUST_OVERRIDE_ON          0x00000001      /* RW--V */
#define NV_NVLDL_RX_CONFIG_RX_POLARITY_OVERRIDE               28:28           /* RWEVF */
#define NV_NVLDL_RX_CONFIG_RX_POLARITY_OVERRIDE_OFF           0x00000000      /* RWE-V */
#define NV_NVLDL_RX_CONFIG_RX_POLARITY_OVERRIDE_ON            0x00000001      /* RW--V */
#define NV_NVLDL_RX_CONFIG_RX_REVERSAL_OVERRIDE               29:29           /* RWEVF */
#define NV_NVLDL_RX_CONFIG_RX_REVERSAL_OVERRIDE_OFF           0x00000000      /* RWE-V */
#define NV_NVLDL_RX_CONFIG_RX_REVERSAL_OVERRIDE_ON            0x00000001      /* RW--V */
#define NV_NVLDL_RX_CONFIG_RX_SKIP_TOGGLE_CONST               30:30           /* RWEVF */
#define NV_NVLDL_RX_CONFIG_RX_SKIP_TOGGLE_CONST_OFF           0x00000000      /* RWE-V */
#define NV_NVLDL_RX_CONFIG_RX_SKIP_TOGGLE_CONST_ON            0x00000001      /* RW--V */
#define NV_NVLDL_RX_CONFIG_RX_DEBUG_ENABLE                    31:31           /* RWEVF */
#define NV_NVLDL_RX_CONFIG_RX_DEBUG_ENABLE_OFF                0x00000000      /* RWE-V */
#define NV_NVLDL_RX_CONFIG_RX_DEBUG_ENABLE_ON                 0x00000001      /* RW--V */
#define NV_NVLDL_RX_SLSM_STATUS_RX                            0x00003014      /* R--4R */
#define NV_NVLDL_RX_SLSM_STATUS_RX_SUBSTATE                   3:0             /* R-EVF */
#define NV_NVLDL_RX_SLSM_STATUS_RX_SUBSTATE_STABLE            0x00000000      /* R-E-V */
#define NV_NVLDL_RX_SLSM_STATUS_RX_PRIMARY_STATE              7:4             /* R-XVF */
#define NV_NVLDL_RX_SLSM_STATUS_RX_PRIMARY_STATE_HS           0x00000000      /* R---V */
#define NV_NVLDL_RX_SLSM_STATUS_RX_PRIMARY_STATE_EIGHTH       0x00000004      /* R---V */
#define NV_NVLDL_RX_SLSM_STATUS_RX_PRIMARY_STATE_TRAIN        0x00000005      /* R---V */
#define NV_NVLDL_RX_SLSM_STATUS_RX_PRIMARY_STATE_SAFE         0x00000006      /* R---V */
#define NV_NVLDL_RX_SLSM_STATUS_RX_PRIMARY_STATE_OFF          0x00000007      /* R---V */
#define NV_NVLDL_RX_SLSM_STATUS_RX_PRIMARY_STATE_UNKNOWN      0x0000000d      /* R---V */
#define NV_NVLDL_RX_SLSM_STATUS_RX_SURPRISE_LD_CNT            15:8            /* R-EVF */
#define NV_NVLDL_RX_SLSM_STATUS_RX_SURPRISE_LD_CNT_INIT       0x00000000      /* R-E-V */
#define NV_NVLDL_RX_SLSM_STATUS_RX_FENCE_STATUS               31:31           /* R-EVF */
#define NV_NVLDL_RX_SLSM_STATUS_RX_FENCE_STATUS_OFF           0x00000000      /* R-E-V */
#define NV_NVLDL_RX_SLSM_STATUS_RX_FENCE_STATUS_ON            0x00000001      /* R---V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL                          0x00003280      /* RW-4R */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_FLIT_CRC           0:0             /* -WEVF */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_FLIT_CRC_INIT      0x00000000      /* -WE-V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_FLIT_CRC_CLEAR     0x00000001      /* -W--V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_LANE_CRC           1:1             /* -WEVF */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_LANE_CRC_INIT      0x00000000      /* -WE-V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_LANE_CRC_CLEAR     0x00000001      /* -W--V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_RATES              2:2             /* -WEVF */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_RATES_INIT         0x00000000      /* -WE-V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_RATES_CLEAR        0x00000001      /* -W--V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_REPLAY             3:3             /* -WEVF */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_REPLAY_INIT        0x00000000      /* -WE-V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_REPLAY_CLEAR       0x00000001      /* -W--V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_ECC_COUNTS         4:4             /* -WEVF */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_ECC_COUNTS_INIT    0x00000000      /* -WE-V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_CLEAR_ECC_COUNTS_CLEAR   0x00000001      /* -W--V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_SHORT_RATE               8:8             /* RWEVF */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_SHORT_RATE_ENABLE        0x00000001      /* RWE-V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_SHORT_RATE_DISABLE       0x00000000      /* RW--V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_LONG_RATE                9:9             /* RWEVF */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_LONG_RATE_ENABLE         0x00000001      /* RWE-V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_LONG_RATE_DISABLE        0x00000000      /* RW--V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_RATE_COUNT_MODE          10:10           /* RWEVF */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_RATE_COUNT_MODE_FLIT     0x00000000      /* RWE-V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_RATE_COUNT_MODE_SEQUENCE 0x00000001      /* RW--V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_FLIT_COUNT_MODE          11:11           /* RWEVF */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_FLIT_COUNT_MODE_FLIT     0x00000000      /* RW--V */
#define NV_NVLDL_RX_ERROR_COUNT_CTRL_FLIT_COUNT_MODE_SEQUENCE 0x00000001      /* RWE-V */

#define NV_NVLDL_RX_ERROR_RATE_CTRL                           0x00003284      /* RW-4R */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_SHORT_THRESHOLD_MAN       2:0             /* RWEUF */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_SHORT_THRESHOLD_MAN_INIT  0x00000001      /* RWE-V */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_SHORT_THRESHOLD_EXP       3:3             /* RWEUF */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_SHORT_THRESHOLD_EXP_INIT  0x00000000      /* RWE-V */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_SHORT_TIMESCALE_MAN       6:4             /* RWEUF */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_SHORT_TIMESCALE_MAN_INIT  0x00000000      /* RWE-V */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_SHORT_TIMESCALE_EXP       11:8            /* RWEUF */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_SHORT_TIMESCALE_EXP_INIT  0x00000006      /* RWE-V */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_LONG_THRESHOLD_MAN        18:16           /* RWEUF */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_LONG_THRESHOLD_MAN_INIT   0x00000001      /* RWE-V */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_LONG_THRESHOLD_EXP        19:19           /* RWEUF */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_LONG_THRESHOLD_EXP_INIT   0x00000000      /* RWE-V */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_LONG_TIMESCALE_MAN        22:20           /* RWEUF */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_LONG_TIMESCALE_MAN_INIT   0x00000000      /* RWE-V */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_LONG_TIMESCALE_EXP        28:24           /* RWEUF */
#define NV_NVLDL_RX_ERROR_RATE_CTRL_LONG_TIMESCALE_EXP_INIT   0x00000006      /* RWE-V */
#endif // __lr10_dev_nvldl_ip_h__
