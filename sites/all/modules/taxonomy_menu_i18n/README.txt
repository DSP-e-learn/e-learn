Taxonomy translation and Entity translation support for taxonomy_menu. Translated menu items are synchronized with the
term translations.

Installation
------------
Enable the module.

Configuration
-------------
- Set translation mode to "Translate and Localize" for the menu you use with taxonomy_menu.

- Edit your vocabulary and enable your preferred translation choice:
  - Disabled. Menu items will not be translated.
  - Localize. Menu items will be localized using string translation.
  - Translate. Term translations will be created as translated menu items. Missing translations will not be available
    in the menu.

- Check "Rebuild the menu on submit" and save the vocabulary.