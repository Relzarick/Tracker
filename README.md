# SIMPLE INVENTORY TRACKER

A minimalist CRUD app to track items, quantities, and prices.

## FEATURES
You can add, track, and delete entries. The info button links to the repo.


* **Name** – Product or item identifier.

* **Qty** – Current stock count.

* **Price** – Cost per unit.

* **Desc** – Brief item description.

## DESIGN CHOICES

* **GUI Framework (FLTK):** No particular reasons.

* **Storage (SQLite):** Needed something simple.

* **UI (Builder with Director Pattern):** Builder separates UI construction into reusable components, while the Director helps me to compose components into complete UI elements.

* **Backend (Mediator Pattern):** Separates entry state and DB interaction into a single class, keeping the Director clean and focused only on composition.

## SETUP & RUN
Clone repo and compile.


## TODO
1. Switch to a repository pattern.
2. Add multi-folder support.