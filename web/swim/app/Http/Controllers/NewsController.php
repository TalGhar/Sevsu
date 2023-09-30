<?php

namespace App\Http\Controllers;

use App\Models\News;
use Illuminate\Http\Request;

class NewsController extends Controller
{
    public function store(Request $request)
    {
        $validated = $request->validate([
            'news_title' => 'required',
            'news_text' => 'required',
            'news_image' => 'image|mimes:jpeg,jpg,png'
        ]);
        $image = $request->file('news_image');
        $imageName = 'News' . time() . rand(1, 1000) . '.' . $image->extension();
        $image->move(public_path('news_images'), $imageName);
        $validated['news_image'] = $imageName;
        if (News::create($validated))
            return response()->json(['success' => true]);
        return response()->json(['success' => false, 'errors' => ['asd' => 'dsa']]);
    }

    public function receive()
    {
        $awards = News::all();
        return $awards;
    }

    public function edit(Request $request)
    {
        $news = News::find($request->id);
        $news->news_title = $request->title;
        $news->news_text = $request->text;
        $image = $request->file('image');
        if ($image) {
            $imageName = 'News' . time() . rand(1, 1000) . '.' . $image->extension();
            $image->move(public_path('news_images'), $imageName);
            $news->news_image = $imageName;
        }

        $news->save();
        return response()->json(['success' => true]);
    }

    public function delete(Request $request)
    {
        $award = News::find($request->id);
        $award->delete();
    }

    public function latest()
    {
        return News::latest()->take(3)->get();
    }
}
