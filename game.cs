// Scissors, rock and paper game using only polymorphism

using System;

public abstract class Variant{
    public abstract string againstScissors();
    public abstract string againstRock();
    public abstract string againstPaper();
    public abstract string play(Variant v);
}

public class Scissors : Variant{
    public override string againstScissors(){
        return "TIE";
    }
    public override string againstRock(){
        return "PLAYER 1 WON";
    }
    public override string againstPaper(){
        return "PLAYER 1 LOST";
    }
    public override string play(Variant v){
        return v.againstScissors();
    }
}

public class Rock : Variant{
    public override string againstScissors(){
        return "PLAYER 1 LOST";
    }
    public override string againstRock(){
        return "TIE";
    }
    public override string againstPaper(){
        return "PLAYER 1 WON";
    }
    public override string play(Variant v){
        return v.againstRock();
    }
}

public class Paper : Variant{
    public override string againstScissors(){
        return "PLAYER 1 WON";
    }
    public override string againstRock(){
        return "PLAYER 1 LOST";
    }
    public override string againstPaper(){
        return "TIE";
    }
    public override string play(Variant v){
        return v.againstPaper();
    }
}

public class Game
{
    public static void Main(string[] args)
    {
        Paper p = new Paper();
        Scissors s = new Scissors();
        Rock r = new Rock();
        Console.WriteLine(r.play(s));
        Console.WriteLine(r.play(r));
        Console.WriteLine(p.play(s));
        Console.WriteLine(r.play(p));
    }
}