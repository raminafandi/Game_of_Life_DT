#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "game/cell.h"
#include "game/gameplace.h"
#include "clipped/clipped.h"
#include "circular/circular.h"
#include "game/gameplace.h"

int setup() { return 0; }
int teardown() { return 0; }

void test_gameplace_funcs_NOT_NULL()
{
    Gameplace gameplace = newgameplace(5, 5);
    Cell **array = createCells(gameplace);
    CU_ASSERT_PTR_NOT_NULL(addRandomFullCells(gameplace, 4));
    CU_ASSERT_PTR_NOT_NULL(playGame(gameplace, array, 1));
    CU_ASSERT_PTR_NOT_NULL(playGame(gameplace, array, 2));
}

void test_clipped_funcs_full1()
{
    Gameplace gameplace = newgameplace(5, 5);
    Cell errcell = newCell(-1, -1);
    Cell **array = createCells(gameplace);
    array[0][0].isFull = 1;
    array[0][1].isFull = 1;
    array[1][0].isFull = 1;
    array[1][1].isFull = 1;
    CU_ASSERT_EQUAL(1, (checkFullCellDeadorAlive(gameplace, array, 0, 1).col == errcell.col && checkFullCellDeadorAlive(gameplace, array, 0, 1).row == errcell.row));
}

void test_clipped_funcs_full2()
{
    Gameplace gameplace = newgameplace(5, 5);
    Cell errcell = newCell(0, 1);
    Cell **array = createCells(gameplace);
    array[0][0].isFull = 1;
    array[0][1].isFull = 1;
    array[1][0].isFull = 1;
    array[1][1].isFull = 1;
    array[1][2].isFull = 1;

    CU_ASSERT_EQUAL(1, (checkFullCellDeadorAlive(gameplace, array, 0, 1).col == errcell.col && checkFullCellDeadorAlive(gameplace, array, 0, 1).row == errcell.row));
}

void test_clipped_funcs_empty1()
{
    Gameplace gameplace = newgameplace(5, 5);
    Cell errcell = newCell(-1, -1);
    Cell **array = createCells(gameplace);
    array[0][0].isFull = 1;
    array[0][1].isFull = 0;
    array[1][0].isFull = 1;
    array[1][1].isFull = 1;
    array[1][2].isFull = 1;
    CU_ASSERT_EQUAL(1, (checkEmptyCellDeadorAlive(gameplace, array, 0, 1).col == errcell.col && checkEmptyCellDeadorAlive(gameplace, array, 0, 1).row == errcell.row));
}

void test_clipped_funcs_empty2()
{
    Gameplace gameplace = newgameplace(5, 5);
    Cell errcell = newCell(0, 1);
    Cell **array = createCells(gameplace);
    array[0][0].isFull = 1;
    array[0][1].isFull = 0;
    array[1][0].isFull = 1;
    array[1][1].isFull = 1;
    CU_ASSERT_EQUAL(1, (checkEmptyCellDeadorAlive(gameplace, array, 0, 1).col == errcell.col && checkEmptyCellDeadorAlive(gameplace, array, 0, 1).row == errcell.row));
}

void test_circular_funcs_full1()
{
    Gameplace gameplace = newgameplace(5, 5);
    Cell errcell = newCell(-1, -1);
    Cell **array = createCells(gameplace);
    array[0][0].isFull = 1;
    array[0][1].isFull = 1;
    array[1][0].isFull = 1;
    array[1][1].isFull = 1;
    CU_ASSERT_EQUAL(1, (checkFullCellDeadorAlive_Circular(gameplace, array, 0, 1).col == errcell.col && checkFullCellDeadorAlive_Circular(gameplace, array, 0, 1).row == errcell.row));
}

void test_circular_funcs_full2()
{
    Gameplace gameplace = newgameplace(5, 5);
    Cell errcell = newCell(0, 1);
    Cell **array = createCells(gameplace);
    array[0][0].isFull = 1;
    array[0][1].isFull = 1;
    array[1][0].isFull = 1;
    array[1][1].isFull = 1;
    array[1][2].isFull = 1;
    CU_ASSERT_EQUAL(1, (checkFullCellDeadorAlive_Circular(gameplace, array, 0, 1).col == errcell.col && checkFullCellDeadorAlive_Circular(gameplace, array, 0, 1).row == errcell.row));
}

void test_circular_funcs_empty1()
{
    Gameplace gameplace = newgameplace(5, 5);
    Cell errcell = newCell(-1, -1);
    Cell **array = createCells(gameplace);
    array[0][0].isFull = 1;
    array[0][1].isFull = 0;
    array[1][0].isFull = 1;
    array[1][1].isFull = 1;
    array[1][2].isFull = 1;
    CU_ASSERT_EQUAL(1, (checkEmptyCellDeadorAlive_Circular(gameplace, array, 0, 1).col == errcell.col && checkEmptyCellDeadorAlive_Circular(gameplace, array, 0, 1).row == errcell.row));
}

void test_circular_funcs_empty2()
{
    Gameplace gameplace = newgameplace(5, 5);
    Cell errcell = newCell(0, 1);
    Cell **array = createCells(gameplace);
    array[0][0].isFull = 1;
    array[0][1].isFull = 0;
    array[1][0].isFull = 1;
    array[1][1].isFull = 1;
    CU_ASSERT_EQUAL(1, (checkEmptyCellDeadorAlive_Circular(gameplace, array, 0, 1).col == errcell.col && checkEmptyCellDeadorAlive_Circular(gameplace, array, 0, 1).row == errcell.row));
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS)
    {
        CU_get_error_msg();
    }
    CU_pSuite s = CU_add_suite("operations", setup, teardown);
    CU_add_test(s, "Gameplace funcs", test_gameplace_funcs_NOT_NULL);
    CU_add_test(s, "Clipped funcs", test_clipped_funcs_full1);
    CU_add_test(s, "Clipped funcs", test_clipped_funcs_full2);
    CU_add_test(s, "Clipped funcs", test_clipped_funcs_empty1);
    CU_add_test(s, "Clipped funcs", test_clipped_funcs_empty2);
    CU_add_test(s, "Circular funcs", test_circular_funcs_full1);
    CU_add_test(s, "Circular funcs", test_circular_funcs_full2);
    CU_add_test(s, "Circular funcs", test_circular_funcs_empty1);
    CU_add_test(s, "Circular funcs", test_circular_funcs_empty2);

    CU_basic_run_tests();
    CU_basic_show_failures(CU_get_failure_list());

    return CU_get_number_of_failures();
}
