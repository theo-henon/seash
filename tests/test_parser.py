from os.path import basename
import pytest

from utils import get_shell_scripts


@pytest.mark.parametrize("script", get_shell_scripts("./parser"), ids=lambda script: basename(script.path))
def test_parser(script):
    assert script.run_pretty_print_from_str() == script.run_pretty_print_from_str(use_ref=True)

