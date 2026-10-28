# Push\_swap team plan

A working plan for redoing push\_swap as a team, reusing the 2022 infrastructure and replacing only the algorithms.

## What you keep and what you replace

The checker links none of the algorithm files, and the sorting is called from one place: the `push_swap()` dispatcher in `push_swap.c`. That makes the split clean.

**Keep (infrastructure):** `arg_check`, `create_node`, `del_stacks`, `dup_stack`, `error_delete_all`, `execute` / `execute_c`, `push_stack`, `swap_stack`, `rotate_stack`, `reverse_rotate_stack`, `sorted`, `stack_sorted`, `printstacks`, `checker`, and all of libft.

**Replace (algorithm):** `small_sort`, `bucket_sort`, `rot_calc`, `high`, `low`, `finalize`, `get_stack_data`, `choose_pot`, `t_pot_list_tools`, plus the `t_pot` struct and its prototypes in `push_swap.h`.

## Decisions to make together first

1. **Add an `index` field to `t_stack`.** Right now a node only holds `data`. Almost every modern approach (radix sort, Turk) is much easier if each number is replaced by its rank (0 to n-1) before sorting. It touches `push_swap.h`, `create_node.c` and `dup_stack.c`, so one of you should do it on a short branch and merge it before anyone starts the algorithm work.
2. **Which big-sort algorithm.** Radix sort on ranks (binary digits) is very simple and is usually enough for the 100-number target, but it usually misses the 500-number one. The Turk / cost-based approach is harder but gets both. Since there are two of you, one option is to have one person build each and benchmark them against each other.
3. **Parsing scope.** `main` currently handles each argument as one number and doesn't split a single `"3 2 1"` argument. Decide whether you want that.

## Branch structure

Skip a `develop` branch. For two people it's overhead you'll forget to maintain.

- **`main`** always builds with `make` and passes your test script. Nobody pushes to it directly.
- **Short-lived branches**, one per todo item, with a prefix: `feat/small-sort`, `feat/turk-algorithm`, `fix/parse-int-overflow`, `chore/gitignore`.
- **Merge via pull request**, and the *other* person approves it. Even a 30-second glance catches forgotten debug prints.
- **Delete the branch after merging**, so your branch list stays a list of work in progress.
- **Leave the old algorithm in place until the new one beats it.** Give the new files different names (say `sort_radix.c`, `sort_turk.c`, `sort_small.c`) and switch the call in `push_swap()` on the branch. A final `chore/remove-old-algo` PR deletes the old files, so `main` always has a working fallback.
- **The `Makefile` is your conflict hotspot.** It lists every source file by hand, so every new file means an edit. Add all the new filenames in one small commit, or have a single person own that file.

### Habits for two chaotic people

- Run `git pull` on `main` before creating a branch, and commit small and often.
- Split work by file where you can. Whoever owns an area owns those files for the week.
- Add a `.gitignore` first (`*.o`, `*.a`, `push_swap`, `checker`, `.vscode/`). Committed binaries and `.o` files are the number one source of pointless conflicts.
- Tell the other person before touching `Makefile` or `push_swap.h`.

## Todo list

### Phase 0: together

- [ ] Commit the Linux fix, remove tracked binaries, add `.gitignore`
- [ ] Add `index` to `t_stack` and a `normalize()` function that assigns ranks
- [ ] Write the benchmark script (3, 5, 100 and 500 numbers, avg / worst / fail) and record your old numbers as the baseline (about 800 moves for 100, about 7,000 for 500, 12 for 5)

### Phase 1: split

**Person A: big sort**

- [ ] Implement the chosen algorithm in new files
- [ ] Combine `rr` / `rrr` where it saves moves
- [ ] Tune until you hit about 700 moves for 100 numbers and about 5,500 for 500

**Person B: small sorts and edges**

- [ ] Optimal 2, 3 and 5 number sorts (a hardcoded case table is fine)
- [ ] Parsing and error edge cases: `INT_MIN` / `INT_MAX`, `+5`, `-0`, `""`, duplicates
- [ ] Checker prints `Error` on an invalid instruction instead of `KO`
- [ ] Valgrind on both programs, including error paths. The old `TODO` file says "find leak in checker"; the `checker()` rewrite removed one likely culprit (the stray `ft_strdup("")`), so confirm that.

### Phase 2: together

- [ ] Remove the old algorithm files and the `t_pot` code
- [ ] Norminette, Makefile checks (`make` twice must not relink, `re` works), dead code cleanup (including the `loc_h` leftover in `high.c`)
- [ ] Test on a fresh clone
