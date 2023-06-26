<?php
class AlbumModel extends Model
{
    public function get_data()
    {
        return [
            ['name' => '1.jpg', 'description' => 'н̸̡͍̫̹̰͇͉̟̘̠̭̱͈̂͑̅̒̅̆͘͘͝у̸̢̨͔͓̹͇̹̖̞̙̫͔̼̠̂̌͌̀̃͑̋̎͛̋͛͘ ̶̡̤͉̯̠̏̌͋̈́̔͆̓̈́̄̅̀͂͛̉͝с̵̨̘̜̬̦͓̭̮͚̱̜̬̿̊͌̌н̶̧͎͆̂̀́̌̕о̵͙̻̿̿̉̉̿̀͝в̸̺͎̤͎̝̹͇͈͈͓̈́͛̈͗̒̍͆̽ͅа̷̢̡̧̤̪̥͈̭͓̥̤̱̗̘̍͑̍̓̓̂̄͐̄̾̌̄͊ ̶̛̖̳̾̐͒͒̈̏̓я̴̮̲͔̣̺̼́̓̂̈́͊̑̕,̴̞̯̰͈̞̿͑̅̃̊͌̊̈́̓̅̾͘͝ ̵̛͉͙̲͎̱̰͚͓͔̹̻̜̺̲̏̈̓̆͒͐́͊͐͝т̸̨͖͎͕̝̰̣͚̣̬̭̳̤̰͑̄́͋͊́͊̈́̅̈́̾͘͜͠и̵͙͈͉̭̟͔͇͕̬͍͖̯͎̦̺̂̄̒̍п̵̧͙̮̭̼̣̮̍̇̀̐͗͝а̶̘̭̹̤̻̝̩̹̰̣̘̇̒͒͐̏̕'],
            ['name' => '16.jpg', 'description' => 'ў̴͓̓̓́̌̽͊̽̓̌̔̇͒͌͆з̶̭̘̖̯̦̳͖͓̯͍̹̗͉̉͊̀̒͂͛н̸̧̲̤͔̰̼̥͖̺̈̍͌̎̆̇̈́̐͋̓̈́а̷̗̤̤̯̦̗̖̦̭͎͎͉̎͗̏̽̕͘л̵̡̢̢̻̦̘͎̻̙̪͓̺̟̥̰̾̓̏̾͑̄̈͠͝и̵̛̛͉̺̟̿͒̍̒͌́ ̷̛͉̝̞̖͓͋̈́̆̔̒̎̃͂́̕̕с̷͈̫͚̯̮̔̊̇̊͑̂̎͌̚̕̚ͅо̷̬̥̃̋̚г̷̺̻̦͍̥̲͎̊̾̐͛͠л̴͚̝̹͉͙̘̞̗̈́̃̒̈́̄͆̈́̾͊́̋͝а̵̛̳͎̯̺̲̣̰͎͛͑͗͜ͅс̵̨̛͔͐̑͑̋̑̊̈̋̍̍̓̂̕͝н̷̧̛̤̭̼̰̞̼̤̭̱̳͔̳̝̑̓̌̀̂͐͜͝ы̴̹̘̭̳̗͍̏̋͂̓'],
            ['name' => '17.jpg', 'description' => 'о̴̢̨̨̨͇̻̙͓̲͕̟̱͇̤̳̦͉͚͔̤̮͍̬̥̜̩͈͔͉̤̦̹͚̩̫̤̘̰̰͉̖̣͎̰͓̬͖͖̼̝̗͖̹͉̺̳̭̙̩̩͇̯̼̬̬̭͔͙̜̬̝̝̘͖̪̟̺͔͚̰̝̫̥͗̎̇͛͑́͒̊̈́̾̍̉͘͘͜͠͝ͅͅͅт̵̢̛̛̖͓̙͈̥͓̲̱̞̳̤̹̱̘͍͇̥̥̦̳͙̯͉̱̩͚̙̫̪̪̤͖̮̰̳̬̥̠̗̬̠̤͌̒̈́̈́̿̊͗̈͗̊͗̔̔͆́̆̿͐̿͛͊̽̌̉͑̔̓̏͒̄͋̌͒̑̍͆̇̆̕͘̕͜͝͝ͅ ̸̡̨̡̡̨̨̢̨̛̼̪̺̠̣̫̙̪͙̩͖̯̜̰͙̘͕̲̺̱̘͈̫̳̯̺͖̗̟̼̻̻̟̬͈̙͎͈̪̰͉͈̬͎͍͕̲̪̰͔̲̲͙̤͚̤̰̮̼͎̜̘̬̘̞̣͔͈͈͚̦͈̦̮̫̖̻̬͓̣͎͙͓̯̠̭̩̳̩̣̲̣̮̥̱̙͖̺̠̙̤̮̺͈̼̗̮͕̊́̊͑̏̅͊̂̽̀̌̀̈̾̍̅̈́́́̀͘̕̚͘͜͜͠ͅͅс̴̨̧̨̡̢̢̨̛̭͔̭̣̥̲̣͔͔̯̣̪͔͓͖͖͙͍̥͖̘̥͈̠̻̦͉̜̘̭̗̙̱̞̪̤͎̤͈̲̲̫̼̦̖̭̥̺̮̮̳̺͖̘̱̙̗̣̯̺̹̯̬̟̭͐̃̊̈́̓́̋̀͆̃̋̆͑̆̽̽̐̄͐̒̚̚͜͠ͅͅͅё̵̧̢̡̡̡̡̧̧̢̨̡̢̛̛̛̣͖̲̦̞̲̺̠͙̤̪̰͇̥̞̫̰̙̟̘̩̹͍̰͎̖͎̞̳̙̟̬̳̳̭̲̰͍͍̳̪͓͕̳͓̰͓̼͚̮̖̦̩̩̘̫̤̯̬̬̹͈̳̼̹̘͇̼̞̫̖̮̠̭̹̼̝̠̱̙̻̤̤̳͓̬̪̤̲̯̰͉̙̘̖̥͔͇̠̻̙̈́̾̈̄̒̑̑̓͌̋̓͂̆͛́́̄́̋̒̈̃̐͛̀̔̑̀̍͐̇̃͆̅̒̐̊̒͂̋͐͒͆̃̉̿̃̅̔̀͂͑̓͑͐̔͆̈́̊̏̆̏́̌̿̏̆̓̃̿́̈́͌̅̊̀͐̄̏͊͂̈͒͗͛̓̃̕̚͘̚̕͜͜͝͠͝͠͝͝͝͠͝͠͝ͅр̵̢̡̨̡̧̢̧̡̛̛̭͚͇̖̞͖̻̣̞̫̯͖̬̟̖̻̹̜̣͈̜̱̫͖̥͇̹̦̙̝̘̺̺͍̙̮̩̟̿̀̒͛̀̈́̉̐͒̇̾̄̀̾͑͂̍̓̿́͗̐͊̉͊̅̇̈́̄̏͌̅̍͐͌̈́̇̿̀̇͛͐̑̉̾̋͋̓͆̊̔̃̐̐͑̀̀̈́͑͂̏͐͐̉̍͑͛̅͋͐̽̌̎̀̃̌̅̆̍͊̓̍̍̑̒̇͛̊͛͑͆͐̊͋͊͌̕̚͘͘̚͘̚̚̚̚̕̚̕͘̕͝͝͝͝͠͝͝͝͝д̵̡̡̨̛̟͈̻̰̘͇̯̜̗̙̗̭͖̼͍̮̜̦̰͍̻̼͇̗̲͓̫͕̖̺͇͓̼̳̲̳͙̪̺̬̫͇͍̯̰͓͕̥̟̺̬̝͓̖̥̪̘̞͚̩̞̱̦̖̣̼̜̦͑́͗̾͆̇̍͗̎͛̔͌́̒͊̊͊͑͂̏̅̉̒͑̇́̋͊́̈̄̍̈̓̈͐̽̿̒̈́̾̾͐̈́͊͑̄͊́̓́̾͗̊̓̎́̒̽͌̋̈́́̓̏̉̽̋͗̾̒͑͐̃͋̋̿̆̋̇́̐̾̃̽͒̊̎̓̍̚͘̚̕̕̚͘͘̕̕͜͜͜͠͝͝͝͝͠͝ц̸̨̢̡̢̧̨̛̛̙͍̹͚̣͚̣̞̞͉̜̦̹̣̺̦̪̻̞̙̜̘͕͔͖̟̥̥͖̯̟̥͚͙̼̫͔̥̦͇͍̜͓̖͙͉͓̱̳̜̤̠͉͍̼̘̼̼̼̗͖͑̀͒́̅͛͛͂͐͑̈̆͌́͑̈̐̓̄͆̉̎͐̄͌͑̕͜͜͜͝͠͠͠ͅа̴̡̢̨̡̨̨̢̧̛̛̼͍̺̱͓̺̠͍̥̲̩̟̗̤̫͕̭̞̝̤̘͖̹̬̺̯̰̪̘̘͎͎̖̥̣̝͚̝̹͔̲̹̯̥̰̖͎͕̺̬̠̼̫̟̻̭̠̹̣̤͖͕͍̗͉͉̦͎̘̻͚͉̙͖͉͎̭͙̥͓̫̟̠̥̲̮̜̥̗̠͖͓̭̠̲̱͇͓̘̟͓̝̙̪̖̺͚̟͚̼̾̒̑͒́̉̀͆͊͛͒̋͗͌̿̍͛͆͊̒͊̈́͋̂͒̀̃͋̒̔͌̂̀̈́́͐̾̿͂̅͗͋͒͒̿̂͗̈́͌́͂͌́̾̉͒̿͑̑̐̃͆̈̎̐͘̚̕̕͜͜͝͠͝͝͠͠͝͠ ̸̡̢̧̧̮̠̙̟̟̱͖̳̤̬̤̠͔̪̝͚͇͖͔͔͍͖̰̥̻͎̬͍̖̭̰̟͈̺͕̙͖̤̞̱̣̥̞̻̲͙͖̞̠͎̟̤̞̖̣̥̬̣͔̮̮̪͖͕̓̃̊͒̄̀̄̎̓̂͜͝и̵̢̢̡̧̧̧̢̨͕̮̟̩̣̦̤̖͖̣͈͕̬̝̭̙̙̖̯̳̩̮̙͙̻̪̙̜̫̠̖̳͍̺̹̮̘̗̘͎̼̱͆͆̍̈́̋̇͗͗̂̈̒͑̐̋̀͛́̑͂̾̇̌̈́̉͒̓͌̉̎̓̈́̽̋̿͋̔̽̂͆̌̊̊̌̌͛͋̀̈̈̈́́̈́̉͐̑͗̾̾̂̈́̾̇̉͊̐̈̍̅̑̀̈́̇́̓̔̓̊͆̕̕͘̕̕̕͝͝͝͝ͅ ̷̛̪̣̹̠̩̝̮͒̌̑̉͌̍͊͋͌̎̑̐̒̒͐́̊̀͆̾̍̊̽̋̒͊̈́̃̓̑́͆͒͌̂͛̂͗̽͂͌̿̏̓͋̇͛̓͗̌̃̅͌̉̑̇̊͌̎̂̋͆̀͆̐̈̃́̽͂̈́̃̈́̓͗͘͘͘̕̚̚͝͝͠͠͝͝п̶̛͇͕͈̪͕͍̥̟̼̖̫̭̣͓̑̐̌̂̃̃̀͗̄̾̒̈͒̑́͋́͂̊̈́̈́̂̇̆̽̍͆̊̅͑̌͒̍̈́̒̔̐̀̑̒̆̀͛̑̈́̒̚̚̕͜͝͝͠͠ͅо̴̢̡̨̢̧̡̙̪͚͓̦͈͖̣̝̥̺͖̳̻̮̺̳̣̘̲̬̱̺̬̼͇̻̖͇̹͓͈̩̺̃͆̊̈́͑̏̒͒̃́͒̀͐̆̂͊̅͛̋̄̓́͑̇̚ͅͅч̵̨̡̨̱͉̩͈̠͍̥͚͎͉͇̭̙̖͚̬̣͕̥̹̬̩͉̠͚̻̟͈̗͖̰͍͍̙̮̻̭̰͇͇͔̎̈́͐́е̷̡̧̨̢̨̨̛̛͉̲̣͇̫̠͙̞͙̱̻̞̠͓͉̙̹̼̯̮̝͔̠̭̞̖̖̭̭̼̦̬͚̻̭͚̿͒̈́̇̋̏̀̈́̐̽̈́̅̈́̏̒̇͊̽͋͛̿͑̎̀̽̈́̉̄̒̏͒̓̽͂̃̈́̇͋̔͑̄̑́̈́̂̒̿̈́́̋̃̆̇̒̾̀̓̽͑̕̚̚͘͜͝͝к̶̢̡̧̢̨̦̹͕͖̘̺͕͕͚̜̰̝̟̙͓̰̼̬̗͎̘̺̺͕̣̬͉̖̖̗͚̗̪͖̹̍́̈́̄́̐̽́̀̐̆̈́̈́̽̍́̀͒͒̍̾̎́͒̐͘͠͝͝ͅ'],
            ['name' => '18.jpg', 'description' => 'c̵̡̨̧̨̧̢̛̛̛̛͙͍̠͈̫̜̱͙̪̯͕̙̹̪̲̯̭̞̗̭̫̲͔̟̬̤̙̻̱̬̬̱͍͈̝̤̞̰̟͖̭̼͕̫̤͈̅̄̀̎͌́̿͌̉̃̐̂̌̆̒̈́́̏̆̈́̇͗͑̋̈͒́̿͐̋̇̀̇̃̎̿͗̓̋̄̿̊̃̔́͋̌͂̉͑̂̿̂̅͌̃̾͌̅̐͐̈́̈́̐̄͊̆̈́͋̍̋͌̿͗̔̈́̈́̄̎̍͗̌͑̇̂̾̔̈̿͛͊̋́͂̔̇͑̑̇́̅͋̈́̍̋̄̃̓̾͛̄̾̐̽͑̂̑̐̋̇̑̒̽͑͆̉̽͐̌͗̅̍̀̂̈́̚̕̚͘͘͘͘̕̕̕̚͜͝͝͝͠͠͠͠͝͝͝͠ͅh̷̡̧̧̡̢̡̛̛̠͕̖̯̤̬͚̭̰̠͓͙̣̘̪̪͇̗̳̹͍̬͚̬̪̳͚̬̣̭̝͈̤͇̺͈̱̩̣͖͙̖̩̤̙͙̘̯̯̳͒͗͊̌̾̿͗́͐̓́̅̐̂̅̈̍̄̈̂̓̊̀͗̈́̽̃̈́̑̚͜͠͝͝͝͝ͅͅͅͅà̵̢̧̧̡̡̛̛̛͎͖͈̞̤̜͙̼̲̭͉̭̯͔̰̥̻͆̽͐͛͂̒̆̃̊̀̋͑̋̊̋̂̿̀̓̀̀̂̓̽̔́́̑̌̆̂̔͒̏̄̅̌̈́̋͐̽̉̒̿̓͆̅̎̄̀̋͛̾̿̈͒͐̓̐̒̀́͛͒͑̑̆̅̃̿̆͘̕͘͘̚̕̚͠͝͝ͅd̶̨̡̢̢̧̨̨̧̢̨̛̛̛̛̛̜̬̬͖̻͖̯̲̖̲̼̦̪̤̙̳̘̦̠̺̹͇̮͓̝̝̘̦̦̞̖͚̼̼̰͈̖̖̗͚̮̖̙̲̙̫͈̪̙̗̭̙̩͎͖̱̣͕̜̣̞͉̜̼͉̹̬̖̞̤̯̬̣̭͓̥̥̬̭͍͎̮̳̮͔͕̣̺͓̲͙͉̘̫̳̬̥̩̝͓͙͓̫͇͇̭̞̜̝̬̱͎̞̖̬̮͓͖̻͍̙͉͎͈͇̲͇̼̤̟͉̰̺̗̩̜͉̣̪̞̑͊͆͗̇̐̎̂͒̔̽̒̂̅̐͋̽̿̿̎͆̾͂̀̆̐̉̑̈͌͛̐͐̑̉̀͒̒́̀̾͌͆̈́̐̋̐͌̃̅́̏̍̈̿̃́̔̌̿̾͐̌́̓̈́̏͌̐̉͊̒͑͋̽̾̀͘͘̚̕̕̚͜͝͠͠͝ͅͅͅͅͅͅ'],
            ['name' => '19.jpg', 'description' => 'т̵̨̨͈̜͉͕͈̝̗̫̪̩͇̠̩͈̩̤̝͖̞͕͓̼̫̗̣̆̋̾̀̃̏̐́̆̽̊̔̎̄̀̾̏̌̽͑̽̕͘̚ѐ̵̡̧̛̬̺͍̞͚͇͙̯̗̼͓̦̞͍̼̥̗̀̈́͂̒̈́̒͋̔͊͑̋̂́͋̃̇̏̕͘п̵̨̧̢̞̹̬̻͚̼̤̟̘͓̘̞̟̞̳̭̂̎̌͒̈́̓́̂͋͐̈͛̈́̈͐͋͗̑́̈́̈́́̊͐̋͗͘̕͜͝ͅе̵̡̥̥͉̼̻̫͋̋̌̓̾͒̎̚р̵̛̛̬̾͛̈́̄̃̀̍͌͂̔̌̌̽̇͌̆̿͒̉̓͊̋̈́̾̓̚ь̷̨̛͍͕͎͍̬̯͔̳͋͊̏̆́̍͂̏̐̔̾̉̅͐̇̃́̿̌͘̕̕͝͝͝ͅ ̶̢̨̢̰̗̘͔̣͖͎̜͇͙̠̣̹͚̹̠͓̠̀̽̆̅͂́͊͗͌̿͑̎̇̆̂͘̕͜͠о̸̛̺̥̺̏́̑͐̉̈͂̊͋͂̑̏͊̏͗͆̍̏̾̆͝͝н̴̨̛̪̜͎̜͎̮̒́͋̾̇̔̃̑̓̐̎̇̒̆̅͌̐̇̓͆̀͊͌̃̒̄͘͝͠ ̴̡̡̨̧̖͎̖̞̮̦͔̬̭̘̞͓̞̤̳̫̲̹͓͎̱̘̲̣̌̀̉͂̆͜͝ͅп̴̢̧̨̫̳͖̥̟̖͓͎̻̖̲̗͎̳͖̳̲̲̬̼̯̓͛̌̀̇͑̒̔̇̀̑̓̊̂͂̇͛̌̅͂̀͂́́͗̚͝ӧ̵̨̼́͒̈́̒͒з̴̢̧̛̭̺̥̼͍̥̳̰͚̮̙͈̪̹̖̠̞̥̱̤̮̥̩͕̳̬̯̔͛͂͊͊͑͒͗̈́̈́͋͊̉͒͆̍е̷̧̛̟͓͈͚͖̙̮̯̼̞͔͍͎̳̔̎̋̊̑͛͐͊̍͒͒͋̾̌̚̕͝͠р̵̡͖̣̙͕̙̝̰̖̫̗͎̱̯͉̆̾̿̊̈̎̉̾̇͒̆͒̅͑̍́͘͝͝,̸̢̧̨̤̗̖͍̼̮̺͓͓̘̗̠̳̲͔̺̜͐̂̇́̋̉̐̈́̂̈́̽͌͌͋͌̋̈̈̈́̐͝͝͝͝ ̴̧̩̠̗̼͕̬̲̻͗̎̑͂́̕͜п̸̨̻̯̦̤̗̬̼͈͖͎̲͉̦̭̜̻̼̭̺̇̅̉͊͊͑̓̀́̒̌̽̏̀̄̀̔̅́͆̄̀̿͛̃͒̊̊̆͘͝͝ͅо̴̡̧̢̛̠͇̳̫͔͖̙̣͙͓͖͈͎̇́̍̈́̈̈̐̉̂͆̒̅͊̔̃͌̾̋̒͜͠͝л̶̨̥̜̠̺͈̠͖͇̩̘̹̣̜̻̺̜̱͕͈͙̗͚͛͒͒̓̈́͂͜у̸̡͂̑̀̔͋̐͆̎̇̀͋̿̄̒̃̆̋̏̅̇͒̿̒̇̚͠ч̴̝̦͓̙͔̰̞̟̮̼̠̭̙͐̍͒̚͝а̵̨̡̠̪̠͇̭͓̣̦̲̟͙͇̤͕͈̼̰̥̜̝̼͉͊̌̊̓͑̌̎̏̾͛͗̔̈́̓͛̋͑͗͌̌̄͛̾̊̚ё̷̨̡̛̘̞̦͔̳̥͈̝̥̪̟̲̲̠͓̳͍̖͕̠͍̯̪̉̊̉͋͋̋̏̀͛̅̏͝͝ͅт̸̨̛̖͚̼̻̱͍̦̜̟͎̭͖̲̬͊́̎̄̏̽̾̅̓̀͑̈́̊̔̈́͠͝͠с̸̢̨̨̨̣̹̤͙͖̹͍̥̰̬̰͖̫͚̬̮̯͓͙̮͎̙̹͉̒͂̉͐̆̀̿̈͛̿̾̂̾̈̓̅͂̃̌͐̉̆́̐̑̆͜͠͝я̷̢̗̹̺͔̜͍͔̩̝̥͌͒͆͑͛̈́͐̓̋̎͒͗̓̎͑̎̒͋̑̉̆̽̋͌̚̚̕͘̕͠'],
            ['name' => '20.jpg', 'description' => 'ṗ̴̨̡̛̛̤͉͙̮͕̰̤̘̘̰̱͈̱̲̦͍͇̞̯̮̲͔̪͇̝͖̻̥̩̻̘̀́̔͐̑̍̅̔̄̂͌͋̂̽͆̉̿̋͂̈́̓̐̌̾̀̓̇̈́̄̿̅̉̆̈́̔̇̇̂͆͗͊͒͂̌̂̓̈́͂̋̓̄̄̄͐̃̆̍̅̎̒̒̍̌̐̕̚͘̚̕̚͝͠͝͝͠ͅo̴̢̡̢͇̘̠̖̠͖̰̜͍͙͉̜̠̞̞̗̪̱̝͓̱͖͖͛͑̓̆̈́̊̽̓̔̎͋̇͑̈́͛͑̀͑̔̈́̆̍̋͂̉̅͆̆͂̍̆̄̋͐̈́̃̂͌̊̋̈́͒̔͒̆̍́̀͛̽͊̋̀̓̓́̔́̚͘͠͝͠͝͝͠ͅļ̵̛̛̛̛̛͍̲͙̬̬̀̊̒͊̂̈́̈́̏̿͆͑̀̃̍͊͗͋̓̓͌̆̈́͗͂́͌̉͒̑̆̂͂͊̊̈̂̐͘̕͘̕͜͠͝͝͠͝͝z̸̡̢̢̛̛̘͇̘̪͇̭͖̺̬̼̝̣̪͔̟̝̦͖̞̭̰͎͙̬̭̠͓̠̗̱̜͎͎̪̪̭̗̫̞̣̣̥̜̜̖̺̪͕̭̬̳̀̆͒͛̋̀̐̌̎̀̔̊͗͂͊̌̓͑̐̄͒̾͐̈́̎̎̆̈̓̿̎̔̄̄͂͋̄͌̽̽͂͌̿̈́̇̅̀̾́̐͗̑͆͆͋̇̑́̓̏̀̓̉̀̊͘̚̕̕̕͘͜͝͝͝͝͠y̶̢͚̥̗̹̮̦̘̘͙̩̟͇͙̮̳͉̺̜͕̯̥͑͒̎̀̉͗̒̑̈̑̐̎͂͒̾͊̀̈́͠t̴̢̡̧̧̢̧̡̨̛̛̩̙͍̱̪̩͔͙̠̪̱̝̙̞̺̗̙̰̠̗̯͉̠̫̮̳̙̫͍͍̻̟̜̠̹̗̬̰̲̬̪̹̩̟̭͉̬̬̬̦̞̜͉͔̦̙̥̯̼͑͆͗̊̏̒̄̽̆̽̔̐̊́́̐̆̂͌̊͐̀̽͋̓̑̆͆́̏͆́͑͂̒̀̍̆̏̇͂͋̔̊̈́͑̌̋̅̈́͂̏͂̽̂̈̊̔͐̒̔͘͘͜͜͜͜͜͠͝͝ͅ ̴̢̨̧̥͚͕̙̠̮͚̱͚̟͙̜̠̹͉̦̣̹͕̜̯̻̰̹̠̞̰͚̹̣̬̳̙̥̥̳͔̺͙̬̻͇̭͛̊̃͆͛̇̎̑̍̓͋̏̈́̋͛̒̉̾̌̀̊̈́͋̀͘͜͜͝͝͝͝ͅͅͅͅv̸̹̬̫̖̒̾͂͐̒͂͗̿̆̓̓͛̀̌̉̒͊͑͆͑̏͆̾̊̀͋̎̏̂́̿͛̃̈̄̀̇͗͆̈̂͋͘͘͘̕̚͝͝ȅ̸̢̧̧̛̲̻͇̣̦͔̲̘̦̣̲͓̠̜̜͇͇̤̟̟̼̥̼̫͖̦̤̣̱͍̰̬̖̯̠̫̘͉̘͙̞̪̣̺̹͇̯̹̳̻̗͙̭͉̟̳̔͑͐̄̇͆̌̈́̓́͒̈̀̋̃̓͗͋̓̾́͆̃͐̓͋̌͐̒͒̉̓͒̊͊̃͊̎̏́͗̈́̐̈́̓͗̊͑̂̔͐͐̒̚͘̚͜͜͜͜͝͠ͅͅͅḑ̸̨̢̡̢̡̛̛̛̜̳̱̯̰̙͕͍̣͓̻͎̯̫͔̜̼̩͉̘͉̭͈̭̤̻̭̻͕̦͙̠̗͇̠̠̳̟̪̬̺͙̥̠̗͍͎͎̙̜̤̺̤͎̭͇͕̤̅̑̉́̿͊̄̓̈̍̈́͒̌͛̀̏̅̌͋͗̈́͗̀̌̀̑̆̅̂̽̾́̎͗̌̍̉̽͋̌͑̓͐̐̉̚̚̚͘͘̚͘͜͜͝͠a̶̡̢̡̧̧̧̢̢̦̦͍͉͚̰̘̰̮͓͓̗̖͎̙̖̳͙̖̖͓̹̥̭͔͈̫͖̻̫̪̭͕̤͕̳̜̱̩̗̱̭̖̩̤̻̯̞̫̩̣͔̤͓̗̜̰͓̬̬̮̼̯͓̒͗̈̽́̃̔̃͗̊̓̀̈́͛̿͋̇͒̀̇̈̀̀̉͒̍̔͂̇͋͂̀̽̆̒͐͋͋́̇͑̚͠͠͝͠ͅͅţ̵̧̨̢̡̡̡̛̛͉̦̥̟͔͖̩͎͖͓͔̹͓̬̦͔̟̟̳̱͔̭̪̺͔̹͈̗̜̺͔̱͕̜̤͎͉͔͔͈̳̬̠̫̜͕̫̗̲͕̻̫͂͗̉͂̔͐̅́͋̈́̈́̈̂̏̓̾̓͊̽͆̎͒̀̀̐͂͆͗̃̈́̈́̋͛̈́͂͌̓͆̈̍̊͐̏̑̂͘͘͜͝͝͠͝͝͠͝͝ͅͅb̵̨̧̢̡̛̛̫̫̪͇̘̟̩̫̩͎̰͍̻̤̯͈̜̹̤̤̲͔̭̤̩͕̯̖̬͚̰̼̙̭͈̜̣̬̪͊̈́̑̽͛̄̆̍̀̔̾̅̽͂̄͐͗͛̏͒͆͂͊́͋͛̂̑́̈́͊̆̀̔́̾͆͛̌͗̓͐͊͌̊̓͑́͊̍͂̚̕̕͘͜͝͠'],
            ['name' => '21.jpg', 'description' => 'й̷̨̢̛̪̰̼̱͎̩̼̪̰͂̂͒͗̓̊͠͠͝й̵̧̦̳̜̙̩͆́̑̋͒͘̚й̷͙͉̲͕̋͗̀̕͝й̸̖̼̝͖̹́̿̿͒͐́͑̈́͛ͅй̷̢̰̯̻̘̙͍͇͊̑͊̉̿̊͛͆͊͑͑̓̚͘͠о̵̥̺̲̙͉̓̌̋͊̌'],
            ['name' => '22.jpg', 'description' => 'ну это по факту, кринж делаешь'],
            ['name' => '23.jpg', 'description' => 'н̶̡̨̖̮̣͕̳̲̣̗̭̗͕͈͚͉̎̍̀̌̀̇̓͂̔͑̿̀̅̚͜у̶̡̟̎̌̅̐͐̐̒̃̎͋̓̃͋̈́̓͑͑͑͌̀̿̈̀̈̐̿̒̓̍͗̓̆̑̚̕͘͝ͅ ̸̜͓͕̫̊̓я̷̨̛͙̜̟͉͍̩͇̹͇͔̙̺̻̬̫̹̹͎̪̲̝̹̟̌̋́̓͛̄͌͌̃͛̚͜͝͠ͅ ̷̨̛̘̬̲̥̱͈̤̱͖͚̠̮̭̝̬͓̩̲̫̼͉̞̱̭͔̰̳̪͚̠̘̥̐͗̿̊̊́̓̊̂̆́̓̄͑̓̀̈́̆͋͌̈́̔̓͆͑͛͋̔̆̐̀̚̚͜͠͝͠͝ͅд̸̡̨̬̜͔͙̰̘͎̮͉͓̇̍̔̈́̎͆̄̓͒̽͑̏̔͊͘а̷̢̳̬̮͓͉̜̖͎̼̣̝͕̰̤͓͓͈͈̰̰͈͓͚͖̻͔̹̱̻̹̯̼͈͉̝̜̰͙̔͐͗̎̿́́͊̈̈͗̐͒̾͐̇̕͘͘ ̸̺́̑и̸̳̇̔̌̓͐̅̔͛̊̒̌̓͊̽̂͒͝͝͠ ̷̨̡͕͉͚̖͇̮̙̞̺̘̪̭͕̞̜̼̺̲̯̺̱͉͕͖̮̬̟͓͔̠̫͓̙͕̝̬͈̦͛͆́̒͐͌̓̑̄̄̌́͆̈́̈̎̚̚ч̶̧̡̧̹͕͍̜̱̻̗̺̱̖̱̦͇̬͔͚̖̪̩̱̼͖͈̹̲͌т̷̧̨̩̟̤̹̙̱̣̱̤͙̗̞̗̥͓͚̗̠͙̠̰̬͍̀͑̉̿͑̌̈́̿͊̊͊о̸̢̨̥̹̲͎͇̫̮̫̹̯̹̥̫̙̯̝͍̤̻̦͖͎͉̜͓̩̦͙͚̳̫̟̂̈̅̿̑͆̔̊̂͂͂́͗̿͌͑̍̎̕͠'],
            ['name' => '24.jpg', 'description' => 'м̴̛̛̹̊̈̅̋̊͌̆̿̏́̏͊̔̓̃̀́͒̕ы̶̡̛̬̲͍̥̭͕̔͗̀̽̈̑̍̅́̍̑̀̈́̄͝͠͝ ̸̡̣̗͖̩̱̲͈͍̲͔̝̦̩͈̹͖̥͔͍̻̻̻̉̒͋͐͛͆͗̅̑̏͆͛͌̓̽͋͂̃̐͋̄͊̃̓̆̽̒̒̀̀͛͆̉͘̚̚͜͠͝з̴̢̨̢̛̮͙̘̗̩̓͗̀͌̿̈́̿͌̔̂̂͛͋̄̀̒̾̇̚͝͝͠ͅа̶̨̭̹̠͔̗̼̩̫̳̦̿͆͑̾̎̏́̏͌͝ ̶̢̼̯̙̳̲̙̖̪̝̤̘͈͚̣̀̏̆̈́̈́́̍̑̈́̔̍̇̈́̑͊̉̄̊̏͊̈́̋̓̍́̉̑̔̀̀̕͝͝ͅк̷̡͙̬̱̱̮͓̩̲̗͓͚̖͉̪̝̑͐̂̇̊̆̈́̒̌̄̀̓͒̂̀̽̊̌͆́̽͑̓̓̀̎͆͆́̈͛̾̕̚͝͝͝͝͠͠у̵̨̢̛̤͈̟͍̳̫̫̖͓͕͕̖͈͙̜͊͛͆̋͆̿̅̏̒̔̔̌̿̉͛̈̈́͑̐̍́̔͛̈̍̓̚̕͘͝͝͝л̸̡̡̨̧̤͓̲̫̖̻͕̱͇̲͚͉̤̮͚͕̝̙̳̲̲̣̞͆̊͊̋̔̄̋̀͂̋̄̃̒̂͊͒͂̏̋̿̉̈͌̐̿̆́́͆̒̄͋̋̐̚͜͝͝ь̷̛͎͓͇̊̋̈́͗̎͊͆̅́̓̅̄̆́͛̀̅̓̈́̇́͒̎̄̉̅̅̀͛̾͌̿͐̕͘͘̕̚͝т̴̢̡͖̰̮̮̺̹̠̝̯̭̲͇̲̜̱̮͖͕͍̜̰͈̻̮̔̈́̃̽͛̑̔̏̒̍̂̀̍͂̕͜͝у̸̢̧̙̹͖̩͇̹͔̹̻̫̥̝̱̥̣̗̱̯̺̩͋͛̽̉̌͋͜͜͜͝р̵̧̨̨̛̠̫̜̲̬̗͔̱̥͍̲̭̭͇̜̻̜̳̣͖̲̯̦̺̮̰͍̘̣̀́͋̌̎̊̂͊͛̅̊̋͌͐̇͐̈́͘͜͠͝у̴̧̢̡̢̦͇͈̮̭̱͖͙̤̮̱͖̻͕͚̻̤̙̪͚̺͙͎͓̒͌͐̔̽̾͗̏̀̿̋͋̉̆̆̓́̏̀͊̃̉̈̈́͑̅͊̕͝ ̷̡͔̝͈͇̯͓̫̤̪̺͍̜̙̯͎̮͕̟̰̝͍̘̯̄̐̓̀̇͊͊͒͘͠ͅэ̵͙̼̹͕̝̗̤͓̌́̄̔̃͝͠м̴̛̼͖͎̳̪̠̳͍̻̘̗̼̠͍̗͈̘̩̬̻̤̭̭̪̟͕͐͒̑͗̅̈́̾̀́́̽̆̿̀͛̏͊̚͜͜͠о̸̨̢̨̡̪͇̬̩̟̖͈̤̭͚̼͕͓̱̯̙̩̰̤͍̳̽͌̿͆̀̈́̕'],
            ['name' => '25.jpg', 'description' => 'v̸̡̡̞̬̺̩̗̯̤͚͍͙͍̽̿̋͑̊̉͊̒̈̈́̎̋͆̄̉͐͛́̅̈́̚͘͜͝ͅȨ̶̧̱̙͈̥̦̞͈̙͍̥̭̝̩͍̩̣̗͖̬͙̰͓̳͆͐̔́͂̋̓͋̂̀̐͊́̿̂͐͐̈͂̏̍̚͘͜͝͠ͅd̷̡̛̯͎̜̭̯͔̫̮̦̝̬̬͍͔̖͕̤̝͆̐͆̂̈͌̇̀͐͂̀̍̆̑̍̍́̅̌̌̾̓̔͒̈́̏̓̅̄̔͑̊̐̈́̕͝͠ͅA̵̧̛͙̹͖͔͇̳̦̺̹̮̘̖̫̙͉̩̯͔̘͉̭̹͉̽́͆̈͋̂̐̅̔̏̀̀͛͊̈́̒̓͋̆͌͊̄́̃̍̑̕͘̕͜͝͝ẻ̶̡̨̛̝̪̙̜͍͙̪͉̙̹̬̭̳͔̞̜͔̥͈̼̺̜̬̮̹̯̺̹̭͖͇͚̭̒͐̒͂͂̈̂̓̏̑͗́̀̇͐̔̄̏̒̄̆̿͌͒̇̿̚͜͝͝ͅͅͅȚ̴̡̡̨̢͙͇̦̬̫͓̗͙̦̘̥̣̣̻̖̰̳̖̺̩̼͖͙̙̫̤̪̲͙̈́̓̀͑̒̍͊͑͐̔̔̎̋̍͒̄̋̀̾̐̾̈́͌͐̐͗́̓͒͘̕͘͝͝ͅ'],
            ['name' => '26.jpg', 'description' => 'r̵̨̢̛̬̩̱̫̺̙͓̙̲̜̖̭̬͖͙̬̗̈́̐́̿̏̔͋͌̇̀̊̑͂̏̋̊͘͝ͅḙ̸͙̮͍̙̣̘͕͉͕͉͔̎͑̊̾͜͠ͅå̵̧̨͍̹̝̣̗̻̹͈̻̩̯͕͙̫̎̈̌̈́̋̄͒͋̒̎̑̌̋͐̚͝l̸͔͈͍͕̐ ̷̡̡̡̺͈̫̗͖̫͉̤̠̜̪͎̺̏̋̋͋̏͘t̵̛͓̀̊̓̈́̍͊͒̓̀̾̾͂̿͠ä̷̗̙̭̳̘͍̝͙́̐̃̃̽̆̾͒̚͜͜l̴͉͍̙̠̣̥̱̣̝̱̦͍͔̟̬͕̝͊̈́̅̽̿̇̆̅̎͑̾͐͝k̴̛̥͎̰͎̀͛̎̊̊̒̃̋̓̃͂͆͊̃̃̚̚͜͠ͅ'],
            ['name' => '27.jpg', 'description' => 'h̶̨͎̞̼̝͇̩̗̬̟͊̓̓̐́̽́͑͗ͅͅȁ̴̡͕̜̣̝͚͈̳̳͖͕͐́̅̽̈́̂̀̐̕̕͜h̷̡̨͕̺͇͇̥̙͎̞̜̦̻̋̊̀̓̓̍̀̽̄̑͊̏͆̎͊̆̚̚ ̷̻̙͈̺͎͔̩̘̗̲̗͂̈́̒̽̅̀̊d̶͓̞̤̥͐̽̆̈́̓̈́̅̔͋͋̌͠ȧ̵̞̳̠̽͂͑ṫ̴̨̥͔͇͂̆̓̽̀͑͊̚ͅ ̶̡̠̬̜͖͕̦͆͑m̸̢̡͍̦̗̘̯͇͕̙̲͍͓͖̼̗̲̯̖̮͖̐̐̔̔̎̓̾͌̑̊̉́͌̃͐̽͌́̃ͅê̷̡̨̹̖̰͚̺ ̸̨̰͙̼̱̟̜͚̝͕̯̬͉̜̞͖͕̮̦̪̙̀̌̓́͊̎̊̾͑̅̚ͅ3̷̢͇͉̼͙̻̩̺̹̯͎͙̥̗͎̠̱͙̭̘̦̑̏̒̾̅͋̈́̽͌̋̍̌̏̉̓͊̐͗͘͝ ̵̨̥̙͎̃̅͊́͋̽̀͋̎̃̇ỳ̴̨̡̭̱̱̹̖̯̗̯̬͙͚̫̻͗̀̾̽́̈́̊̈́̂̋̎̏̽́͘͜͝r̴̢̛̬͈̜̤̝̱͛̈̓̏̈́̓͊̍̂͛̓͘͘͝ş̵͔͎̲͖͓̟͔̰̞̲̰̔̄̓̈́̏̈́̈́͆͝ ̷̨̙̜̟̥̜̝̭̠̫̞̘͒̍̊̊̈́̏̽͌̅̓̌̉̓̚̕̚͜a̴̘̘͋̄͗̀ģ̷͚̱̤̖̙͉̮̪͈̝̰̗̑͑̏̑͊̄ͅö̴̡̡̢̝͖͔̣͎̪̼̬̹̟̦͙̃̽̊̿̿͛͊̈'],
            ['name' => '28.jpg', 'description' => 'лучше волков ничего в этой жизни не будет'],
            ['name' => '29.jpg', 'description' => 'Н̸̱̩̣͉̙̟̱͉͕͚͚̜̩͔̗̫͚̬̪̝͍͓̖̀̓̈̅̆̍͐̽̈̓̑̏͒͑͂̀̑͗́̑͛̃̄͆̚͘̕̚͘͜͠͠͝͠Е̶̧̡̨̞̖̫̱̟̬̮͕͚͙̙̳̱͊̽̍̈̉̍͋̏̃̎̆͋̂̐̓̾̇̀͘̚̕̕͝ͅВ̸͔̮͒̇̅̆͒̔Ӹ̶̛̘̞͇͎̮͖͈͌̃̿̎̌̆̀̾̐̃́̌̍̄̏̊̂̏̔̂̋̓̇̂̓̐̚̚͝͝͠Н̵̢̦̼͎̖̻̘̭̣̠̝̟̪̱͓͓̞̠̮͖̹̼̣͍̜̬͖͓̼̱͊̈́͊̀̎͒̍̋̈͛̉̓͋͑̏͋͊̋͋͒̌͒̕͜͠ͅО̸̳̤͇̳̭̓̀͒̈́̆̍̀̊С̶̧̧̢̺͖̜̝̳͙̭̙͚͓̥̩̬͍̞̠̬̞̝̙͚̫͍͇̦̗̆̀̆̑̃̊̀́́̄̓̒̽̎̓̀̀͌̇́̃̚͜͝͠Ѝ̴̛̰̪̖̻͔͉̥͍͙̞̻͍̯̣͓͚̱̯̞̣͐̀́̾̈́͗̎̿̑̃̆͋͌̉̃̂̃͒̀̐́́͗͋̊̇͑̇͆͘͘̕͜ͅМ̵̦̔̌͂̿̾̽͂͗͑͊̈́̓̔̏̅̒͂̄̅̽̿̎̇̎̒̎̓̄̋̍͠͝А̷̨̡͕̼̖͚̼͙̼͕̗̠̝͉̻̻̫̦̃͊̊̾̔̊̆̎̋̈́̐͊̍̋̈́̌̏̔͝ͅЯ̵̡̛̞̠̏̿̇́̿͆̓́̾̽͗͊̔̔̇̃͐̀̊̕̕͠͠͝͝ ̷̢̧̢̛̛̛̦͚̗̭͔̘͔̭̟̳̙̼͓̞̩̠̞̳̯͙͖̹͕̫̖͍̯̘͓̐̒̄̅̈́͊͗̀͐͒̅̈́̔̀̊͋̈́̂͆͐̇͑̔͂̀́͘͜ͅЛ̵̢̞̩̯̟̜̖́̏̔̋͋͆̈́̋̈́̅̊̀͑̀́̈́͜͝ͅЁ̴̪̪̙̦̻̪͋̈́̏́̀̌̂̇̿̍̇́̿̀̑͑̀͒͋̔̏͐͠͝͝͝Г̸̳̣̻͈͖͙͙͈͖̯̰̫͕͉̞̣̰̤̪̱̜̓̌̇͜ͅК̶̻͎̩͇͔̭͌̌О̵̡̬̲͙̞̭͇̲̼̩̪̻͖͕͎̳̖͖͕̘͎̬̰̻͚̞̭̹͌̇͆̃̂͗͂̄͝͝С̵̧̝̟̪̠͔̪̲̹̠̟̻̎̔̓͛̈̂̓̾͑͆͐́̽̓̎̌̀̆̂̅̍͋͋̈́̈͂͜Т̸̢͓̜̥͎͈̹̯̫͍͕̝̲͖͕̉̇͜Ь̴̛̞̭̦͈̙̊̽̋̅̓͗̀̍̉̓́̊͐́͌̃̏̽̈̉̃̋͝͝']
        ];
    }

}