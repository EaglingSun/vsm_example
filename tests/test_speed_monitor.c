/* test_speed_monitor.c - 차속 판정 요구사항 테스트 (스위트 test_speed_monitor)
 *
 * 지금은 러너가 도는지 보는 스모크 케이스 하나만 있다. 요구사항(SR) 별 케이스는 실습에서 이 파일에 더한다.
 * 판정 케이스는 brake_on = false 로 부른다 (제동이 등급에 주는 영향은 요구사항에 없다).
 */

#include "vsm_test.h"
#include "speed_monitor.h"

/* SR-003: 150 km/h 초과 200 km/h 미만 -> MID */
static void sr003_speed_151_is_mid(void)
{
    VT_CHECK_EQ_INT(VSM_WARN_MID, sm_evaluate(151u, false));
}

int main(void)
{
    vt_begin("test_speed_monitor", "test-results/test_speed_monitor.xml");
    vt_run("SR-003_speed_151_is_mid", sr003_speed_151_is_mid);
    return vt_end() == 0 ? 0 : 1;
}
